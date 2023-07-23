#include<iostream>
using namespace std;
int wky,lw,m,n;
int rest,nd[5001],w[5001],c[5001],dp[5001],dpt[5001],mx=-1;
int main()
{
	cin>>wky>>lw>>m>>n;
	for(int i=1;i<=n;i++)cin>>nd[i],nd[i]=nd[i]*lw/wky;
	for(int i=1;i<=m;i++)cin>>w[i]>>c[i];
	cin>>rest;
	for(int i=1;i<=m;i++)
	{
		for(int j=rest;j>=nd[w[i]];j--)dp[j]=max(dp[j],dp[j-nd[w[i]]]+c[i]);
	}
	cout<<dp[rest];
}
