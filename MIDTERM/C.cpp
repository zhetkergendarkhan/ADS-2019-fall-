#include <iostream>
  
using namespace std;


void merge(vector<pair<int,int> > arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    vector<pair<int,int> > L, R; 
  
    for (i = 0; i < n1; i++) 
        L.push_back(arr[l + i]); 
    for (j = 0; j < n2; j++) 
        R.push_back(arr[m + 1+ j]); 
      
    i = 0; 
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(vector<pair<int,int> > arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
 
  
int main() 
{ 
    string s;
    int T;
    cin >> T;
    getline(cin,s);
    vector<string> ans[T];
    for(int t = 0; t < T; t++){
        string s;
        getline(cin,s);
        stringstream ss;
        ss << s;
        vector<string> vv;
        vector<pair<int,int> > v;
        int i = 0;
        string word;
        while(ss >> word){
            vv.push_back(word);
            v.push_back(make_pair(word.size(), i++));
        }
        mergeSort(v, 0, v.size()-1);
        sort(v.begin(), v.end());
        for(i = 0; i < v.size(); ++i ){
            ans[t].push_back(vv[v[i].second]);
        }
    }

    for(int i = 0; i < T; i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}