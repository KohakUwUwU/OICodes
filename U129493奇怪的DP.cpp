#include<iostream>
#include<cstdio>
using namespace std;
int m,n,map[2001][2001];
long long f[2001][2001],F[2001][2001],ans=0x3f3f3f3f;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=map[i][j]+max(f[i-1][j],f[i][j-1]);
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)F[i][j]=map[i][j]+max(f[i+1][j],f[i][j+1]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans=min(ans,f[i][j]+F[i][j]-2*map[i][j]);
	cout<<ans;
}
