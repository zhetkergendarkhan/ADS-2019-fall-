#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string bin(int x){
	vector<int> temp;
	while(x > 0){
		temp.push_back(x % 2); 
		x = x / 2;
	}
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); ++i)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < temp.size(); i++){
		if (temp[i] == 0 and temp[i-1] == 1)
			return "YES";
	}
	return "NO";
}

int main(){
	int n;
	cin >> n;
	vector<int> v;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << bin(v[i]) << endl;
	}
	return 0;
}