//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;
double ma[111][111];
double ans[111];
double eps=1e-7;

signed main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)scanf("%lf",&ma[i][j]);
    for(int i=1;i<=n;i++)
	{
        int r=i;
        for(int j=i+1;j<=n;j++)if(fabs(ma[r][i])<fabs(ma[j][i]))r=j;
        if(fabs(ma[r][i])<eps)
		{
            printf("No Solution");
            return 0;
        }
        if(i!=r)swap(ma[i],ma[r]);
        double div=ma[i][i];
        for(int j=i;j<=n+1;j++)ma[i][j]/=div;
        for(int j=i+1;j<=n;j++)
		{
            div=ma[j][i];
            for(int k=i;k<=n+1;k++)ma[j][k]-=ma[i][k]*div;
        }
    }
    ans[n]=ma[n][n+1];
    for(int i=n-1;i>=1;i--)
	{
        ans[i]=ma[i][n+1];
        for(int j=i+1;j<=n;j++)ans[i]-=(ma[i][j]*ans[j]);
    }
    for(int i=1;i<=n;i++)printf("%.2lf ",ans[i]);
    return 0;
}
