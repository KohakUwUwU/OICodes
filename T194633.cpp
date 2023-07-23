//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,timer,a[N],dfs[N],tI[N],tO[N];
vector<int>G[N];
inline void dfs12(int u,int fa)
{
	dfs[++timer]=u,tI[u]=timer;
	for(int i=0;i<G[u].size();i++)dfs12(G[u][i],u);
	tO[u]=timer;
}
int p=0,calc[N];
inline void answer12(int u)
{
	p=0;
	for(int i=1;i<tI[u];i++)calc[++p]=dfs[i];
	for(int i=tO[u]+1;i<=n;i++)calc[++p]=dfs[i];
	int ans=0;
	for(int i=1;i<=p;i++)
	{
		for(int j=i+1;j<=p;j++)
		{
			ans=max(ans,a[calc[i]]^a[calc[j]]);
		}
	}
	cout<<ans<<'\n';
}
inline void sub12()
{
	for(int i=2;i<=n;i++)
	{
		int temp;
		cin>>temp;
		G[temp].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs12(1,0);
	for(int i=1;i<=n;i++)answer12(i);
}
signed main()
{
	cin>>n;
//	if(n<=1e4)
//	{
//		sub12();
//		return 0;
//	}
//	bool ok=true;
//	for(int i=2;i<=n;i++)
//	{
//		int temp;
//		cin>>temp;
//		G[temp].push_back(i);
//		if(G[temp].size()>1)ok=false;
//	}
//	if(ok)
//	{
//		sub3();
//		return 0;
//	}
	sub12();
	return 0;
}

