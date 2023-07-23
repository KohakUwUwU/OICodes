#include<bits/stdc++.h>
using namespace std;
vector<int> e[200001];
int dep[200001],f[200001][21];
int n,q;
inline void dfs(int x,int fa)
{
	for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa)dep[e[x][i]]=dep[x]+1,f[e[x][i]][0]=x,dfs(e[x][i],x);
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int xx=x,yy=y;
	int i=20;
	while(dep[x]!=dep[y])
	{
		if(dep[x]-(1<<i)>=dep[y])x=f[x][i];
		i--;
	}
	if(x==y)return x;
	i=20;
	while(f[x][0]!=f[y][0])
	{
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
		i--;
	}
	int anc=f[x][0];
	return anc;
}
inline int kta(int x,int k)
{
	int i=21;
	while(k)
	{
		if(k>=(1<<i))k-=(1<<i),x=f[x][i];
		i--;
	}
	return x;
}
inline bool on(int k,int x,int y)
{
	if(dep[k]>dep[x]||dep[k]<dep[y]||dep[k]==dep[y]&&k!=y)return false;
	if(kta(x,dep[x]-dep[k])==k&&kta(k,dep[k]-dep[y])==y)return true;
	else return false;
}
int main()
{
	freopen("intersection.in","r",stdin);
	freopen("intersection.out","w",stdout);
	int cnt=0;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		int lca1=lca(u,v),lca2=lca(x,y);
		if(lca1<lca2)swap(lca1,lca2),swap(u,x),swap(v,y);
		if(on(lca1,x,lca2)||on(lca1,y,lca2))cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
