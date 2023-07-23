#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int x[6]={6,5,4,3,2,1};
	int mx;
	for(int i=0;i<6;i++)
	{
		mx=-1;
		if(mx<x[i])mx=x[i];
		cout<<"max="<<mx<<'\n';//ÊµÊ±Êä³ömax 
	}
	cout<<mx;
	return 0;
}

