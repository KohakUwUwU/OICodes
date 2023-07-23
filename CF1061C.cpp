//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
const int MOD=1e9+7;

int n,a[N],dp[N];
 
inline void getInput()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}

inline void calcAnswer()
{
	dp[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)if(a[i]%j==0)dp[j]+=dp[j-1];
	}
}

signed main()
{
	getInput();
	
	calcAnswer();
	
	cout<<dp[n];
	return 0;
}

