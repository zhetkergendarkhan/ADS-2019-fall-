#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
	vector<int> v(s.size(), 0);
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < i; j++) {
			bool b = true;
			for (int k = 0; k <= j; k++) {
				if (s[k] != s[k + i - j]) {
					b = false;
					break;
				}
			}
			if (b) {
				v[i] = j + 1;
			}
		}
	}
	return v;
}

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

int main() {
	string s; 
	cin >> s ;
	string st = s;
	vector<int> v = fast_prefix_function(st);
	for (int i = 0; i < st.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	int cnt = 0;
	for (int i = t.size() + 1; i < st.size(); i++) {
		if (v[i] == t.size()) {
            int index = i - 2*t.size();
			cnt++;
            cout << "Appeared at " << index << endl;
		}
	}
	cout << "Number of appearences: " << cnt << endl;
	return 0;
}

// abcabcd

// 0 0 0 1 2 3 0

// k = p[i - 1];
// s[i] != s[k];
// k = p[k] - 1;
// k = p[k] - 1;
// s[i] == s[k];
// v[i] = k + 1;

// // ab

// // ab#abcabab

// // 0 0 0 1 2 0 1 2 1 2 


