#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fast_prefix_function(string s) {
	vector<int> p(s.size());
	p[0] = 0;
	for (int i = 1; i < s.size(); i++) {
		int k = p[i - 1];
		while (k != 0 && s[k] != s[i]) {
			k = p[k - 1];
		}
		if (s[i] == s[k]) {
			p[i] = k + 1;
		} else {
			p[i] = k;
		}
	}
	return p;
}

int max (vector<int> v){
    int max = v[0];
    for (int i = 0; i < v.size(); i++){
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

int main() {
	int n;
    cin >> n;
    cout << endl;
    string arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        cout << endl;
    }
    for (int i = 0; i < n; i++){
        int sz = arr[i].size();
        vector<int> v = fast_prefix_function(arr[i]);
        int len = max(v);
        if (sz % (sz - len) == 0 ){
            cout << sz - len << endl;
            cout << endl;
        }
        else
        {
            cout << sz << endl;
            cout << endl;
        }
        
    }
	return 0;
}

/*
abcabc
1) a -> 0
2) ab -> 0
3) abc -> 0
4) abca -> a = a -> 1
5) abcab -> ab = ab -> 2
6) abcabc -> abc = abc - > 3
*/

