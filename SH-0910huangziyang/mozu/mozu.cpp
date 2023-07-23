//Project Sekai
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=1e5+5;
const int INF=114514114514;
int n,m,k,f[N];
signed main()
{
	freopen("mozu.in","r",stdin);
	freopen("mozu.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=INF;
	f[k]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		int uu=min(f[v],f[u]+1);
		int vv=min(f[u],f[v]+1);
		f[u]=uu,f[v]=vv;
		if(f[u]>1e6)f[u]=INF;
		if(f[v]>1e6)f[v]=INF;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>1e6)cout<<-1<<' ';
		else cout<<f[i]<<' ';
	}
	return 0;
}
