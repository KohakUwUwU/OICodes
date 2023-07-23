#include<bits/stdc++.h>
#define N (int)5e5+1
using namespace std;
vector<int> v[N];
int f[N][21],dep[N],n,m,s,x,y;
inline void dfs(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=0;i<v[x].size();i++)if(v[x][i]!=fa)dfs(v[x][i],x);
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	cin>>n>>m>>s;
	for(int i=1;i<n;i++)cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
	dfs(s,0);
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	while(m--)cin>>x>>y,cout<<lca(x,y)<<'\n';
}
