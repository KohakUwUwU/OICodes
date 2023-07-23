//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int lowbit(int x)
{
	return x&-x;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<3<<"\n";
			continue;
		}
		if(n==2)
		{
			cout<<3<<"\n";
			continue;
		}
		if(n==3)
		{
			cout<<1<<"\n";
			continue;
		}
		int low1=lowbit(n);
		if(low1==1)
		{
			if(n-lowbit(n)==0)
			{
				if(lowbit(n)==1)cout<<3<<'\n';
				else cout<<lowbit(n)+1<<'\n';
			}
			else cout<<lowbit(n)<<'\n';
		}
		else
		{
			if(n-lowbit(n)==0)cout<<low1+1<<'\n';
			else cout<<low1<<'\n';
		}
	}
	return 0;
}

