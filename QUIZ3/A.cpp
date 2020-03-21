#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, a, b = 0;
  cin >> n;
  
  for (int i=0; i<n; i++)
  {
    cin >> a;
    int ans=0;
      ans=(a-b)/(pow(2,i)) + 97;
    
    cout << char(ans);
    b=a;
  }
  
  return 0;
}