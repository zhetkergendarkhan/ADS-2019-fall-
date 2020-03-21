#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>vec;
  stack<int> st;
  int n, a;
  
  cin >> n;
  int c = n;
  
  for (int i=1; i<=n; i++)
  {
    cin >> a;
    if (a==c)
    {
      st.push(a);
      c--;
    }
    else vec.push_back(a);
  }
  
  while(!st.empty())
  {
    vec.push_back(st.top());
    st.pop();
  }
  
  for (int i=0; i<vec.size(); i++)
  {
    if (vec[i]!=i+1)
    {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
  
  return 0;
}