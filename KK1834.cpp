#include<bits/stdc++.h>
#define N (int)5e5
using namespace std;
struct query
{
	int l,r,p;
}q[N];
int t,cnt,n,m,sz,in[N],out[N],dfn[N],d[N],ans[N],pos[N],color[N];
vector<int>e[N];
map<int,int>vis;
inline void addEdge()
{
	int u,v;
	cin>>u>>v;
	e[u].push_back(v);
	e[v].push_back(u);
}
inline bool cmp(query x,query y)
{
	return pos[in[x.l]]!=pos[in[y.l]]?in[x.l]<in[y.l]:(in[x.l]&1?out[x.l]<out[y.l]:out[x.l]>out[y.l]);
}
inline void dfs(int k,int fa)
{
	in[k]=++cnt;
	dfn[cnt]=k;
	for(int i=0;i<e[k].size();i++)
	{
		if(e[k][i]!=fa)dfs(e[k][i],k);
	}
	out[k]=cnt;
}
int main()
{
	freopen("colortree.in","r",stdin);
	freopen("colortree.out","w",stdout);
	cin>>n;sz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(!vis[x])color[i]=vis[x]=++t;else color[i]=vis[x];
		pos[i]=i/sz;
	}
	for(int i=1;i<n;i++)addEdge();
	cin>>m;
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].p=i;
	dfs(1,0);
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(in[q[i].l]<l)d[color[dfn[--l]]]++;
		while(out[q[i].l]>r)d[color[dfn[++r]]]++;
		while(in[q[i].l]>l)d[color[dfn[l++]]]--;
		while(out[q[i].l]<r)d[color[dfn[r--]]]--;
		ans[q[i].p]=d[q[i].r];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
