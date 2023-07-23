//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int ma[350][350];
signed main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ma[i][j]=114514114514;
	for(int i=1,s,e,h;i<=m;i++)cin>>s>>e>>h,ma[s][e]=min(ma[s][e],h);
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ma[i][j]=min(ma[i][j],max(ma[i][k],ma[k][j]));
			}
		}
	}
	for(int i=1,a,b;i<=t;i++)
	{
		cin>>a>>b;
		if(ma[a][b]==114514114514)cout<<-1<<'\n';
		else cout<<ma[a][b]<<'\n';
	}
	return 0;
}

