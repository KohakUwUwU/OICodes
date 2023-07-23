#include<iostream>
using namespace std;
long long n,dp[5001],sum;
bool judge=true;
int dfs(int set)
{
	dp[set]--;
	while(dp[++set]!=0)dp[set]--;
	return set;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>dp[i];
	while(judge)
	{
		judge=false;
		for(int i=1;i<=n;i++)
		{
			if(dp[i]!=0)
			{
				judge=true;
				i=dfs(i);
				sum++;
			}
		}
	}
	cout<<sum;
}//´í 
