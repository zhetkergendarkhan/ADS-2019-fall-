#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main()
 {
    int n, q;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cin >> q;

    for(int Q=0; Q<q; Q++){
        int l, r;
        cin >> l >> r;

        int ans = 1;
        int prev = a[l];
        
        for(int i = l + 1; i <= r; i++){
            if(a[i] > prev){
                prev = a[i];
                ans ++;
            }
        }

        cout << ans;
    }

    return 0;
}