//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=205;
int n,f[N][3],a[N],sum=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=(f[i][0]=a[i]);
	for(int i=1;i<n;i++)for(int j=1;j<=n-i;j++)f[j][i&1]=max(a[j+i]-f[j][1-(1&i)],a[j]-f[j+1][1-(1&i)]);
	cout<<(sum+f[1][1-(n&1)]>>1)<<' '<<(sum-f[1][1-n&1]>>1);
	return 0;
}

