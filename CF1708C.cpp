//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,q,a[N];
unordered_map<int,int>ma;
inline void work()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i],ma[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		ma[a[i]]--;
		if(a[i]<=q&&q>0)
		{
			cout<<1;
			continue;
		}
		if(q>=n-i+1&&q>0)
		{
			cout<<1;
			q--;
			continue;
		}
		if(ma[q]==0&&q>0)
		{
			cout<<1;
			q--;
			continue;
		}
		cout<<0;
	}
	cout<<'\n';
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}

