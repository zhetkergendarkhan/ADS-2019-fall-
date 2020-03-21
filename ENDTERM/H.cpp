#include <bits/stdc++.h>

using namespace std;

int a[999999] = {};

int main()
{
  int ans = 0
  int q=0;
  string s, s1, s2;
  cin >> s >> s1 >> s2;
  int i=0;
    
  for (i = s.find(s2, i++); i != string::npos; i = s.find(s2, i + 1))
    a[i]=1;
    
  i=0;
  
  for (i = s1.find(s2, i++); i != string::npos; i = s1.find(s2, i + 1))
    if (a[i]==1)ans++;
  
  cout << ans;
  
  return 0;
}