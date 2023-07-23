#include<iostream>
using namespace std;
int n,dp[1001]={0,1};
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)dp[i]=(dp[i-1]+1)*2;
	cout<<dp[n];
}
