//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,m,dep[N],vis[N],out[N],fa[N],ut[N];
vector<int>G[N];
map<int,map<int,bool> >ma;
int q[N],b=1,e;
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
inline void bfs()
{
	q[++e]=1;dep[1]=1;fa[1]=0;vis[1]=1;
	while(b<=e)
	{
		int u=q[b];
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(v==fa[u])continue;
			if(vis[v])
			{
				ut[v]++;
				if(ma[min(u,v)][max(u,v)]==true)continue;
				ma[min(u,v)][max(u,v)]=true;
				out[u]++;
			}
			else
			{
				q[++e]=v;
				fa[v]=u;
				dep[v]=dep[u]+1;
				vis[v]=1;
			}
		}
		b++;
	}
	for(int i=e;i>=1;i--)
	{
		cout<<"---"<<i<<"---\n";
		int u=q[i];
		if(out[u]%2==0)
		{
			for(int j=0;j<G[u].size();i++)
			{
				int v=G[u][i];
				if(ma[min(u,v)][max(u,v)])continue;
				ma[min(u,v)][max(u,v)]=1;
				ut[v]++;ut[u]++;out[v]++;
				cout<<v<<' '<<u<<'\n';
			}
		}
		else
		{
			int pos=0;
			while(pos<G[u].size())
			{
				int v=G[u][pos];
				if(!ma[min(u,v)][max(u,v)])
				{
					cout<<u<<' '<<v;
					ut[v]++,ut[u]++,out[u]++;
					ma[min(u,v)][max(u,v)]=1;
					break;
				}
				pos++;
			}
			for(int i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				if(ma[min(u,v)][max(u,v)])continue;
				ma[min(u,v)][max(u,v)]=1;
				ut[v]++;ut[u]++;out[v]++;
				cout<<v<<' '<<u<<'\n';
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1,u,v;i<=n;i++)scanf("%lld%lld",&u,&v),addEdge(u,v);
	bfs();
	return 0;
}

