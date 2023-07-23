//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ma[15][15],in[15],out[15],tmpin[15],tmpout[15],tto[15],tti[15];
pair<int,int>e[15];
int vis[15];
inline int lowbit(int x)
{
	return x&-x;
}
inline int dfs(int u)
{
	for(int v=1;v<=n;v++)
	{
		if(!ma[u][v])continue;
		if(vis[v])return 1;
		vis[v]=1;
		{
			vis[v]=0;
			return 1;
		}
		vis[v]=0;
	}
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>e[i].first>>e[i].second,out[e[i].first]++,in[e[i].second]++;
//	for(int i=1;i<=n;i++)cout<<in[i]<<' '<<out[i]<<'\n';
	for(int i=0;i<(1<<m);i++)
	{
//		cout<<i<<":"<<'\n';
		int cnt=0,k=i;
		for(int j=1;j<=n;j++)tmpin[j]=tmpout[j]=0;
		for(int j=0;j<m;j++)
		{
//			cout<<"&"<<(1<<j)<<' '<<i<<'\n';
			if((1<<j)&i)cout<<"%\n",tmpin[e[j+1].second]++,tmpout[e[j+1].first]++,ma[e[j+1].first][e[j+1].second]=1;
//			cout<<e[j+1].second<<' '<<e[j+1].first<<' '<<tmpin[e[j+1].second]<<' '<<tmpout[e[j+1].first]<<'\n';
		}
		for(int j=1;j<=n;j++)cout<<tmpin[j]<<' '<<tmpout[j]<<'\n';
		for(int j=1;j<=n;j++)if(tmpin[j]!=in[j]||tmpout[j]!=out[j])goto sbga;
		for(int j=1;j<=n;j++)if(dfs(i))goto sbga;
		while(k)k-=lowbit(k),cnt++;
		cout<<cnt<<'\n';
		for(int j=0;j<m;j++)
		{
			if((1<<j)&&i)cout<<e[j].first<<' '<<e[j].second<<'\n';
		}
		sbga:;
	}
	return 0;
}

