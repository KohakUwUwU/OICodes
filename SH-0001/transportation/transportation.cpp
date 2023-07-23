//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,f[N];
inline int Find(int u)
{
	return u==f[u]?u:f[u]=Find(f[u]);
}
inline void Merge(int u,int v)
{
	f[Find(u)]=Find(v);
}
signed main()
{
	freopen("transportation.in","r",stdin);
	freopen("transportation.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0;
	int ans=-1;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(Find(u)!=Find(v))
		{
			Merge(u,v);
			cnt++;
			if(cnt==n-1)ans=i;
		}
	}
	cout<<ans;
	return 0;
}

