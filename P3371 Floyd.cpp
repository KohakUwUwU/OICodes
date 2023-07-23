//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
const int INF=114514114514;
int a[N][N],n,m,s;
signed main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=INF;
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k||a[i][k]==INF)continue;
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<(a[s][i]==INF?((1<<31)-1):a[s][i])<<' ';
	return 0;
}
