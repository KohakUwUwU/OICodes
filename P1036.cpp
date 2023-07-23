//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=25;
int n,k,a[N],q[N],sum,cnt;
inline bool isPrime(int k)
{
	if(k==2)return 1;
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)return 0;
	}
	return 1;
}
inline void dfs(int step)
{
	if(step==k+1)
	{
		if(isPrime(sum))cnt++;
		return ;
	}
	for(int i=q[step-1]+1;i<=n;i++)
	{
		q[step]=i;
		sum+=a[i];
		dfs(step+1);
		sum-=a[i];
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}

