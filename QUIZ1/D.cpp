#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	bool B=false;
	cin >> n;
	
	int j = 3;
	
	if (n==1)
	{
		cout << 3;
		return 0;
	}
	/*3, 5, 11, 17, 31, 41, 59, 67, 83, 109,
	 127, 157, 179, 191, 211, 241, 277, 283, 
	 331, 353, 367, 401, 431, 461, 509, 547,
	 563, 587, 599, 617, 709, 739,773, 797,
     859, 877, 919, 967, 991*/
	for (int i=2; i<=10000;)
	{
		bool b = false;
		for (int k = 2; k<=sqrt(j); k++)
		{
			if (j%k==0)
			{
				b=true;
				break;
			}
		}
		if (b==false)
		{
		if (n==i && B==true)
			{
				cout << j;
				return 0;
			}
			if (n==i && B==false)
			{
				B=true;
				n=j;
			}
			
			i++;	
		}
		j+=2;
	}
	
	return 0;
}
