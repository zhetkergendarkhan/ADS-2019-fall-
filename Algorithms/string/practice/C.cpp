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
		hashes[i] = hashes[i-1] + ((s[i] - 'a' + 1) * p[i]);
	}
}

int main() {
	precalc();
	string s, t; cin >> s >> t;
    string t1 = t + t;
	long long hash = hashcalc(s);
	hashescalc(t1);
    if (s == t){
        cout << 0;
        return 0;
    }
    int index = -1;
    for (int i = 0; i < t1.size() - s.size() + 1; i++){
        long long temp = hashes[i + s.size() - 1];
        if (i != 0){
            temp = temp - hashes[i-1];
        }
        if (hash * p[i] == temp){
            index = i;
        }
        
    }
    cout << index;
	return 0;
}
