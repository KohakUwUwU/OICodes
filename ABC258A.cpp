//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int n;
	cin>>n;
	if(n<60)
	{
		cout<<"21:";
		if(n<10)cout<<0;
		cout<<n;
	 } 
	else
	{
		cout<<"22:";
		n-=60;
		if(n<10)cout<<0;
		cout<<n;
	}
	return 0;
}
