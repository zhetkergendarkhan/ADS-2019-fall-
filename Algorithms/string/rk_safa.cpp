#include <iostream> 
using namespace std;

long long p[100010];
long long hashes[100010];

void precalc() {
	p[0] = 1;
	for (int i = 1; i < 100010; i++) {
		p[i] = p[i - 1] * 31;
	}
}

long long hashcalc(string s) {
	long long hash = 0;
	for (int i = 0; i < s.size(); i++) {
		hash += ((s[i] - 'a' + 1) * p[i]);
	}
	return hash;
}

void hashescalc(string s) {
	hashes[0] = (s[0] - 'a' + 1);
	for (int i = 1; i < s.size(); i++) {
		hashes[i] = hashes[i - 1];
		hashes[i] += ((s[i] - 'a' + 1) * p[i]);
	}
}

int main() {
	precalc();
	string s, t; cin >> s >> t;
	long long hash = hashcalc(t);
	hashescalc(s);
	/*
	int cnt = 0;
	for (int i = t.size() - 1; i < s.size(); i++) {
		int begin = i - t.size() + 1;
		long long h;
		if (begin == 0) {
			h = hashes[i];
		} else {
			h = hashes[i] - hashes[begin - 1];
		}
		long long newhash = hash * p[begin];
		if (newhash == h) {
			cnt++;
			cout << "Index: " << begin << endl;
			
		}
	}
	cout << cnt << endl;
	*/

	cout << "hash of t: " << hash << endl;
	for (int i = 0; i < n; i++){
		
	}
	return 0;
}


// jfcjfbjfb

// jfb

// a1 + a2 + a3 + a4 + a5 + a6 - a1 - a2 - a3;