//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int n;
int grid[15][15];

void get_input()
{
	scanf("%lld",&n);
	int x,y,v;
	while(scanf("%lld%lld%lld",&x,&y,&v),x|y|v)
	{
		grid[x][y]=v;
	}
}

int dp[15][15][15][15];

inline void calc_answer()
{
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int a=1;a<=n;a++)
			{
				for(int b=1;b<=n;b++)
				{
					if(x+y==a+b)
					{
						dp[x][y][a][b]=max(dp[x][y][a][b],dp[x-1][y][a-1][b]);
						dp[x][y][a][b]=max(dp[x][y][a][b],dp[x-1][y][a][b-1]);
						dp[x][y][a][b]=max(dp[x][y][a][b],dp[x][y-1][a-1][b]);
						dp[x][y][a][b]=max(dp[x][y][a][b],dp[x][y-1][a][b-1]);
						dp[x][y][a][b]+=grid[x][y]+grid[a][b];
						if(x==a&&y==b)
						{
							dp[x][y][a][b]-=grid[x][y];
						}
					}
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
}
signed main()
{
	get_input();
	calc_answer();
	return 0;
}

