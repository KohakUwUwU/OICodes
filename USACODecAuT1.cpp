//TEmPTaTiON
#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int x[N]={(int)-1e9},val[N],type,n,K,dp[5005][5005][2];
long long ans=0;
inline void Solve(int l,int r)
{
    if((r-l+1)%2==0)return;
    int minn=1e9;
    for(int i=l;i<=r;i+=2)minn=min(minn,val[i]);
    for(int i=l+1;i<=r;i+=2)if(x[i+1]-x[i-1]<=K)minn=min(minn,val[i]);
    ans+=minn;
}
inline void Solve1()
{
    int las=1;
    for(int i=1;i<=n;i++)if(x[i]-x[i-1]>K)Solve(las,i-1),las=i;
    Solve(las,n);
    cout<<ans<<'\n';
}
inline void Solve2()
{
    memset(dp,-0x3f,sizeof(dp));
    dp[1][0][1]=0;dp[0][1][0]=val[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=i-2;j++)
        {
            if(x[i]-x[i-1]<=K)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]);
            dp[i][j][1]=(dp[i][j][1],dp[i-1][j][0]);
            if(x[i]-x[i-1]>K)dp[j][i][0]=max(dp[j][i][0],dp[j][i-1][0]+val[i]);
            if(x[i]-x[i-1]>K)dp[j][i][1]=max(dp[j][i][1],dp[j][i-1][1]+val[i]);
        }
        for(int j=0;j<=i-2;j++)
        {
            if(x[i]-x[j]<=K)dp[i][i-1][0]=max(dp[i][i-1][0],dp[j][i-1][1]);
            dp[i][i-1][1]=max(dp[i][i-1][1],dp[j][i-1][0]);
            if(x[i]-x[j]>K)dp[i-1][i][0]=max(dp[i-1][i][0],dp[i-1][j][0]+val[i]);
            if(x[i]-x[j]>K)dp[i-1][i][1]=max(dp[i-1][i][1],dp[i-1][j][1]+val[i]);
        }
    }
    int ans=-1e9;
    for(int j=0;j<=n-1;j++)ans=max(ans,max(dp[n][j][0],dp[j][n][0]));
    cout<<ans<<'\n';
}
signed main()
{
    cin>>type>>n>>K;
    for(int i=1;i<=n;i++)cin>>x[i]>>val[i];
    if(type==1)Solve1();
    else Solve2();
    return 0;
}