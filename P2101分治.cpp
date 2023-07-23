#include<iostream>
using namespace std;
int n;
long long dp[5001],sum;
bool judge=true;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>dp[i];
	while(judge)
	{
		judge=false;
		long long left=-1,right=-1;
		for(int i=0;i<=n;i++)
		{
			if(dp[i]==0&&dp[i+1]!=0&&left==-1)left=i;
			if(dp[i]==0&&dp[i-1]!=0&&right==-1)right=i;
			if(left!=-1&&right!=-1)
			{
				judge=true;
				long long Min=10000001;
				for(int j=left+1;j<=right-1;j++)Min=min(Min,dp[i]);
				sum+=Min;
				for(int j=left+1;j<=right-1;j++)dp[i]-=Min;
				i=right;
			}
		}
	}
	cout<<sum;
}
