#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;

vector<vector<int> > g;
void bfs(int s){
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i = 0; i < g[v].size(); i++){
      int to = g[v][i];
      if(!used[to]){
        used[to] = 1;
        q.push(to);
      }

    }
  }
}


vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j])  ++j;
  pi[i] = j;
 }
 return pi;
}

bool f(int x){
  for(int i = 2; i < x; i++){
    if(x%i == 0) return true; 
  }
  return false;
}

    
int main(){
  string s = "aabaabaaaabaabaaab";
  vector<int> v = prefix_function(s);
  for(int i = 0; i < v.size(); i++){
   cout << v[i] << " ";
  }
  return 0;
}