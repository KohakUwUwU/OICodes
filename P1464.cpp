#include<bits/stdc++.h>
using namespace std;
long long dp[21][21][21],a,b,c;
int main()
{
	for(int i=0;i<=20;i++)
	{
		for(int j=0;j<=20;j++)
		{
			for(int k=0;k<=20;k++)
			{
				if(!i||!j||!k)
				{
					dp[i][j][k]=1;
					continue;
				}
				if(i<j&&j<k)dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
				else dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
			}
		}
	}
	while(cin>>a>>b>>c)
	{
		if(a==-1&&b==-1&&c==-1)return 0;
		if(a<=0||b<=0||c<=0)cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<1<<'\n';
		else if(a>20||b>20||c>20)cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[20][20][20]<<'\n';
		else cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[a][b][c]<<'\n';
	}
}
