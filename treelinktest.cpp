#include<bits/stdc++.h>
#define N (int)5e5+5
using namespace std;
struct query
{
	int opt,x,y,w;
}q[N];
vector<int>e[N],len[N];
int n,nq,x,y,w,fa[N],vis[N],f[N][41],d[N],dep[N];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
inline int Find(int xx)
{
	return fa[xx]==xx?xx:fa[xx]=Find(fa[xx]);
}
inline void Merge(int xx,int yy)
{
	fa[Find(xx)]=Find(yy);
}
inline void addEdge(int u,int v,int l)
{
	e[u].push_back(v);
	e[v].push_back(u);
	len[u].push_back(l);
	len[v].push_back(l);
}
inline void dfs(int k,int fa,int deep)
{
	vis[k]=1;dep[k]=deep;
	for(int i=0;i<e[k].size();i++)
	{
		if(!vis[e[k][i]])f[e[k][i]][0]=k,d[e[k][i]]=d[k]+len[k][i],dfs(e[k][i],k,deep+1);
	
	}
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	int i=20;
	while(dep[u]>dep[v])
	{
		if(dep[u]-(1<<i)>=dep[v])u=f[u][i];
		i--;
	}
	if(u==v)return u;
	i=20;
	while(f[u][0]!=f[v][0])
	{
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
		i--;
	}
	return f[u][0];
}
int main()
{
	freopen("treelink.in","r",stdin);
	freopen("treelink.out","w",stdout);
	scanf("%d%d",&n,&nq);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=nq;i++)
	{
		scanf("%d%d",&q[i].x,&q[i].y);
		int c=getchar();
		if(c==' ')scanf("%d",&q[i].w),q[i].opt=2,addEdge(q[i].x,q[i].y,q[i].w);
		else q[i].opt=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0,0);
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=nq;i++)
	{
		if(q[i].opt==2)
		{
			Merge(q[i].x,q[i].y);
			continue;
		}
		if(Find(q[i].x)!=Find(q[i].y))
		{
			cout<<-1<<'\n';
			continue;
		}
		printf("%d\n",d[q[i].x]+d[q[i].y]-2*d[lca(q[i].x,q[i].y)]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

