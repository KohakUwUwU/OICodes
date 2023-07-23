#include<iostream>
#define int long long
using namespace std;
int n,k,f[5001],a[5001];
signed main()
{
	int i,j,s;
	int ans=-1;
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)for(j=i,f[i-1]=0,s=0;j<=n;j++)f[j]=(f[j-1]*a[j]+a[j])%k,s=(s+f[j])%k,ans=max(s,ans);
	cout<<ans;
}
