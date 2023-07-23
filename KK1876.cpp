#include<bits/stdc++.h>
#define N 501
using namespace std;
int m,n;
double f[N][N];//购买i次有j个不同的铃酱手办 
int main()
{
	freopen("bb5.in","r",stdin);
	freopen("bb5.out","w",stdout);
	cin>>m>>n;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j]*j/m+f[i-1][j-1]*(m-j+1)/m;
		}
	}
	double ans=0;
	for(int i=1;i<=m;i++)ans+=f[n][i]*i;
	cout<<fixed<<setprecision(3)<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
