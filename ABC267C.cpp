//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int a[N],pre[N],ans=-114514114514;
signed main()
{
	int n,m,tmp=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=m;i++)tmp+=a[i]*i;
	ans=tmp;
	for(int i=m+1;i<=n;i++)
	{
		tmp+=a[i]*m;
		tmp-=(pre[i-1]-pre[i-1-m]);
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}

