#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1010
using namespace std;
int dp[MAXN][MAXM][3];
int n,m,x,y;
int p1,q1,m1,n1,p2,q2,m2,n2;
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    scanf("%d%d%d%d%d%d%d%d",&p1,&q1,&m1,&n1,&p2,&q2,&m2,&n2);
    dp[m1][n1][0]=dp[m1][n1][1]=dp[m1][n1][2]=1;//初始化
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int a=1;a<=x;a++)
                for(int b=1;b<=y;b++)
                    if(a!=m1 || b!=n1)//不在小A的位置
                        dp[a][b][0]+=dp[a-1][b][0]+dp[a][b-1][0]+dp[a+1][b][0]+dp[a][b+1][0];
                    else//在小A的位置
                        dp[a][b][0]+=dp[a-1][b][1]+dp[a][b-1][1]+dp[a+1][b][1]+dp[a][b+1][1];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int a=1;a<=x;a++)
                for(int b=1;b<=y;b++)
                    if(a!=m2 || b!=n2)//不在小B的位置
                        dp[a][b][1]+=dp[a-1][b][1]+dp[a][b-1][1]+dp[a+1][b][1]+dp[a][b+1][1];
                    else//在小B的位置
                        dp[a][b][1]+=dp[a-1][b][2]+dp[a][b-1][2]+dp[a+1][b][2]+dp[a][b+1][2];
    int ans=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int a=1;a<=x;a++)
                for(int b=1;b<=y;b++)
                    ans+=dp[a][b][2];
    printf("%d",ans);
    return 0;
}

