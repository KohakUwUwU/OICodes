//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+5;
const int N=5005;
struct Edge
{
	int u,v,w;
}e[M];
int n,m,ans,f[N];
inline bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
inline int Find(int x)
{
	return (f[x]==x)?x:(f[x]=Find(f[x]));
}
inline void Merge(int x,int y)
{
	f[Find(x)]=Find(y);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(Find(u)!=Find(v))ans+=w,Merge(u,v);
	}
	cout<<ans;
	return 0;
}

