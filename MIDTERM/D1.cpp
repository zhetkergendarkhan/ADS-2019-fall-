#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int q;
    cin >> n;
    int h[n];
    for( int i = 0; i < n; i++)
      cin >> h[i];

    cin >> q;

  for( int i = 0; i < q; i++){
    int l, r;
    
    int max = 0;
    int result = 0;
    cin >> l >> r;
    for( int j = l; j <= r; j++){
      if(max < h[j]){
        max = h[l];
        result++;
      }
    }
    cout << result << endl;
  }
  return 0;
}