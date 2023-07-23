#include<iostream>
#include<cstdio>
#define N 1005
#define LL long long
#define R register
using namespace std;
LL G[N][N],f[N][N],n,m,pre[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(R int i=1;i<=n;i++)for(R int j=1;j<=m;j++)scanf("%lld",&G[i][j]);
	for(R int i=1;i<=n;i++)f[i][1]=f[i-1][1]+G[i][1];
	for(R int i=2;i<=m;i++)
	{
		pre[1]=G[1][i];
		for(R int j=2;j<=n;j++)pre[j]=pre[j-1]+G[j][i];
		for(R int j=1;j<=n;j++)
		{
			R LL mx=-0x3f3f3f3f3f3f;
			for(R int k=j-1;k>=1;k--)mx=max(mx,pre[j]-pre[k-1]+f[k][i-1]);
			for(R int k=j+1;k<=n;k++)mx=max(mx,pre[k]-pre[j-1]+f[k][i-1]); 
			f[j][i]=max(mx,f[j][i-1]+G[j][i]);
		}
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<f[i][j]<<" ";
//	cout<<endl;
//	}
//	cout<<endl;
	cout<<f[n][m];
}
