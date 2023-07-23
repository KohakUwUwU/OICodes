#include<iostream>
#include<algorithm>
using namespace std;
long long n,f[1000001],dp[1000001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i>=f[i])dp[i]=max(dp[i-1],dp[i-f[i]]+1);
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
}
