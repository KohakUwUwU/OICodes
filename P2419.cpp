//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int n,m,e[105][105];
signed main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,e[u][v]=1;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[i][j]|=(e[i][k]&e[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int mark=1;
		for(int j=1;j<=n;j++){
			if(j!=i && e[j][i]==0 && e[i][j]==0)
			{
				mark=0;
				break;
			}
		}
		if(mark)ans++;
	}
	cout<<ans;
	return 0;
}

