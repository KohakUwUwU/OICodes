#include<bits/stdc++.h>
#define N 1005
using namespace std;
int m,n,fa[N],w[N],v[N],fail[N],vis[N],last=0;
inline void dfs(int k)
{
	fail[last]=k;last=k;
	for(int i=1;i<=)
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>fa[i];
	for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)if(!vis[i])vis[i]=1,dfs(i);
}
