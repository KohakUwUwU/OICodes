//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int Ns=350;
int n,p;
int G[N],H[N];
signed g[N][Ns],h[N][Ns]; 
signed main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin>>n>>p;
	int L=sqrt(n);
	for(int i=1;i<=n;i++)g[i][1]=1;
	for(int j=2;j<=L;j++)for(int i=j;i<=n;i++)
	{
		g[i][j]=g[i-1][j-1]+g[i-j][j];
		if(g[i][j]>=p)g[i][j]-=p;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i&&j<=L;j++)
		{
			G[i]+=g[i][j];
			if(G[i]>=p)G[i]-=p;
		}
	}
	G[0]=1;
	for(int i=L+1;i<=n;i++)h[i][1]=1;
	for(int j=2;j*(L+1)<=n;j++)
	{
		for(int i=j*(L+1);i<=n;i++)
		{
			h[i][j]=h[i-L-1][j-1]+h[i-j][j];
			if(h[i][j]>=p)h[i][j]-=p;
		}
	}
	for(int i=L+1;i<=n;i++)
	{
		for(int j=1;j*(L+1)<=i;j++)
		{
			H[i]+=h[i][j];
			if(H[i]>=p)H[i]-=p;
		}
	}
	H[0]=1;
	int ans=0;
	for(int k=0;k<=n;k++)
	{
		(ans+=G[k]*H[n-k])%=p;
	}
	cout<<ans;
	return 0;
}

