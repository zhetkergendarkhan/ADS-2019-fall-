#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
 {
    int n;
    int q;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cin >> q;

    for(int j=0; j<q; j++){
        int l, r;
        cin >> l >> r;

        int res = 1;
        int prev = a[l];
        
        for(int i = l + 1; i <= r; i++){
            if(a[i] > prev){
                prev = a[i];
                res ++;
            }
        }

        cout << res;
    }

    return 0;
}