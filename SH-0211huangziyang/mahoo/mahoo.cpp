//LizPlum
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=509;
int n,a[N],b[N],c[N],d[N],e[N];
int cnt,q[N],sum,ans=114514114514;
inline void dfs()
{
	if(cnt==n)
	{
		ans=min(ans,sum);
		return ;
	}
	int now=cnt+1;
	if(b[now]+q[cnt]>e[now]||c[now]+q[cnt]<d[now])return ;
	for(int i=max(d[now]-q[now-1],0ll);i<=e[now]-q[now-1];i++)
	{
		q[++cnt]=i;
		sum+=i*a[cnt];
		dfs();
		sum-=i*a[cnt];
		--cnt;
	}
}
signed main()
{
	freopen("mahoo.in","r",stdin);
	freopen("mahoo.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=2;i<=n;i++)cin>>d[i];
	for(int i=2;i<=n;i++)cin>>e[i];
	d[1]=0;e[1]=c[1];
	if(n<=20)
	{
		dfs();
		if(ans==114514114514)cout<<-1;
		else cout<<ans;
	}
	else cout<<-1;
	return 0;
}
