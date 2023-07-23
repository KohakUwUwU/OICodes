//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;
double dp[1<<16][17],dist[17][17],x[17],y[17];
int n;
signed main()
{
	cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    x[0]=y[0]=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    memset(dp,127,sizeof dp);
    for(int i=0;i<=n;++i)dp[(1<<n+1)-1][i]=0;
    for(int S=(1<<n+1)-2;~S;--S)
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
            	if(!(S&1<<j))dp[S][i]=min(dp[S][i],dp[S|1<<j][j]+dist[i][j]);
    printf("%.2lf",dp[0][0]);
    return 0;
}
