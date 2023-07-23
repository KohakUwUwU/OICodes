#include<iostream>
#include<iomanip>
#define ll long long
using namespace std;
ll maxW,Len,car;
ll w[1001],s[1001];
double ttime[1001],tt[1001][1001],dp[1001];
int main()
{
	cin>>maxW>>Len>>car;
	for(int i=1;i<=car;i++)
	{
		cin>>w[i]>>s[i];
		ttime[i]=Len*1.0/s[i]*60.0;
		tt[i][i]=ttime[i];
	}
	for(int i=1;i<=car-1;i++)for(int j=i+1;j<=car;j++)tt[i][j]=max(tt[i][j-1],ttime[j]);
	for(int i=1;i<=car;i++)w[i]=w[i-1]+w[i];
	for(int i=1;i<=car;i++)
	{
		dp[i]=ttime[i]+dp[i-1];
		for(int j=i-1;j>=1;j--)
		{
			if(w[i]-w[j-1]<=maxW)dp[i]=min(dp[i],dp[j-1]+tt[j][i]);
			else break;
		}
	}
	cout<<fixed<<setprecision(1)<<dp[car];
}
