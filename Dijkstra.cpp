#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
	int val,pos;
	bool operator < (const node &x)const
	{
		return val>x.val;
	}
};
int n,m;//n个顶点 m个边
int a,b,l,st;
int G[1001][1001],dis[1001],vis[1001];
priority_queue<node> q;
int main()
{
	cin>>n>>m>>st;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>l;//输入 
		G[a][b]=G[b][a]=l;
	}
	memset(dis,9989899,sizeof(dis));
	for(int i=1;i<=n;i++)if(G[st][i]!=0)dis[i]=G[st][i];
	dis[st]=0;
	q.push(node{0,st});
	int cnt=1;
	while(cnt<n)
	{
		node x=q.top();
		q.pop();
		if(vis[x.pos])continue;
		vis[x.pos]=1;
		for(int i=1;i<=n;i++)
		{
			if(i==x.pos)continue;
			if(G[x.pos][i]!=0)
			{
				if(G[x.pos][i]+x.val<dis[i])
				{
					dis[i]=G[x.pos][i]+x.val;
					if(!vis[i])q.push(node{dis[i],i});
				}
			}
		}
		cnt++;
	}
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
}
