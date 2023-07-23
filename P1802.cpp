#include<iostream>
#include<map>
using namespace std;
int m,n;
map<int,long long>lose,win,use,dp;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>lose[i]>>win[i]>>use[i];
		for(int j=n;j>=use[i];j--)
		{
			dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
		}
		for(int j=use[i]-1;j>=0;j--)dp[j]+=lose[i];
	}
	cout<<dp[n]*5;
}
