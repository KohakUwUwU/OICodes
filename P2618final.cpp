#include<iostream>
#include<cstring>
#define Max 1000000
using namespace std;
int n,factor[1000001],dp[1000001],prime[100001],pn;
inline void as()
{
	for(int i=2;i*i<=1000000;i++)if(!factor[i])for(int j=i*i;j<=1000000;j+=i)factor[j]=1;
	for(int i=2;i*i<=1000000;i++)if(factor[i])prime[++pn]=i;
}
int main()
{
	as();
	while(cin>>n)
	{
		memset(dp,Max,sizeof(dp));
		dp[1]=0;
		for(int i=1;i<n;i++)
		{
			dp[i+1]=min(dp[i+1],dp[i]+1);
			for(int j=1;j<=pn;j++)
			{
				if(i*prime[j]<=n)dp[i*prime[j]]=min(dp[i*prime[j]],dp[i]+1);
				else break;
			}
		}
		cout<<dp[n]<<endl;
	}
}

