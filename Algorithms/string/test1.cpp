#include<iostream>

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
		hashes[i] = hashes[i-1] + ((s[i] - 'a' + 1) * p[i]);
	}
}

int main(){
    string s, t;
    cin >> s >> t;
    precalc();
    long long h = hashcalc(t);
    hashescalc(s);
    string tmp = "";
    for (int i = 0; i < s.size(); i++){
        tmp += s[i];
        cout << "hash of " << tmp << " " << hashes[i] << endl;
    }
    return 0;
}