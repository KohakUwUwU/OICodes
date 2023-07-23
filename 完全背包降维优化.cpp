#include<iostream>
using namespace std;
int m,n,dp[10001];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int w,c;
		cin>>w>>c;
		for(int j=m;j>=w;j--)dp[j]=max(dp[j],dp[j-w]+c);
	}
	cout<<dp[m];
}
