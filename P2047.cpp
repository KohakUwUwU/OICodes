//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int n,m,ma[105][105],cnt[105][105];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ma[i][j]=114514114514,ma[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,ma[v][u]=ma[u][v]=min(ma[u][v],w),cnt[u][v]=cnt[v][u]=1;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(ma[i][j]>ma[i][k]+ma[k][j])
				{
					ma[i][j]=ma[i][k]+ma[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
				else if(ma[i][k]+ma[k][j]==ma[i][j])
				{
					ma[i][j]+=ma[i][k]*ma[k][j];
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cnt[i][j]&&ma[i][k]+ma[k][j]==ma[i][j])
				ans+=double(cnt[i][k]*cnt[k][j])/cnt[i][j];
			}
		}
		cout<<fixed<<setprecision(3)<<ans<<'\n';
	}
	return 0;
}

