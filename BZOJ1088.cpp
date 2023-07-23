//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int n,a[N],mine[N],cnt;
inline void dfs(int step)
{
	if(step==n)
	{
		if(a[step-1]-mine[step-2]==a[step])cnt++;
		return ;
	}
	mine[step]=a[step-1]-mine[step-2]-mine[step-1];
	if(mine[step]!=0&&mine[step]!=1)return ;
	dfs(step+1);
}
signed main()
{
//	freopen("10.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1)
	{
		if(a[1]<=1)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2])
		{
			if(a[1]==0)cout<<1;
			else if(a[1]==1)cout<<2;
			else if(a[1]==2)cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=0;i<=min(a[1],1ll);i++)mine[1]=i,dfs(2);
	cout<<cnt;
	return 0;
}

