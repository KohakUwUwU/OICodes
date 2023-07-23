#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int len,to;
}qwq;
int n,s,a,b,t,dis[1000005],vis[1000005],vis1[1000005],vis2[1000005],mx[1000005];
vector<node> tree[1000005];
inline void dfs(int k,int l)
{	
	vis[k]=1;
	for(int i=0;i<tree[k].size();i++)
	{
		if(!vis[tree[k][i].to])
		{
			dis[tree[k][i].to]=dis[k]+tree[k][i].len;
			mx[tree[k][i].to]=dis[tree[k][i].to];
			dfs(tree[k][i].to,tree[k][i].len+l);
		}
	}
	for(int i=0;i<tree[k].size();i++)mx[k]=max(mx[tree[k][i].to],mx[k]);
}
int cnt=0;
inline void dfs2(int k,int rv)
{
	vis2[k]=1;
	for(int i=0;i<tree[k].size();i++)
	{
		if(!vis2[tree[k][i].to])
		{
			int rvv=mx[s]-mx[tree[k][i].to];
			cnt+=rvv-rv;
			dfs2(tree[k][i].to,rvv);
		}
	}
}
signed main()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		cin>>a>>qwq.to>>qwq.len;
		tree[a].push_back(qwq);
		swap(qwq.to,a);
		tree[a].push_back(qwq);
	}
	vis[s]=vis1[s]=vis2[s]=1;
	dfs(s,0);
	dfs2(s,0);
	cout<<cnt;
}
