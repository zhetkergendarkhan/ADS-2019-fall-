#include <iostream>
#include <vector>
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

int kmp(string s, string t){
    int cnt = 0;
    string st = t + '#' + s;
	vector<int> v = fast_prefix_function(st);
    for (int i = t.size() + 1; i < st.size(); i++) {
		if (v[i] == t.size()) {
            cnt++;
		}
	}
    return cnt;
}

int main() {
	int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        string temp = "";
        for (int i = 0; i < s.size(); i++){
            temp += s[i];
            if (kmp(s, temp) == s.size() / temp.size() and s.size() % temp.size() == 0){
                cout << temp.size() << endl;
                break;
            }
            else 
            {
                cout << -1;
                break;
            }
        }
    }
	return 0;
}

