//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,a[N],f[N],ans1=-114514114514,ans2=0;
signed main()
{
//	freopen("subsequence.in","r",stdin);
//	freopen("subsequence.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=max(a[i],f[i-1]+a[i]);
		if(ans1<f[i])ans1=f[i],ans2=i;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}

