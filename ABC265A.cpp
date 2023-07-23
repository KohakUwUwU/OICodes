//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int x,y,n;
	cin>>x>>y>>n;
	if(x*3>y)
	{
		int cnt2=n/3;
		int cnt1=n%3;
		cout<<cnt1*x+cnt2*y;
	}
	else
	{
		cout<<n*x;
	}
	return 0;
}

