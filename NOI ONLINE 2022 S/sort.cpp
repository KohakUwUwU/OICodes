 //LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,a[5][N];
inline int check()
{
	if(n==4)
	{
		if(m<=3000)return 1;
		if(m<=5e4)return 4;
		if(m<=1e5)return 5;
		return 6;
	}
	if(n==2)return 2;
	return 3;
}
inline void run1()
{
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			int mn=114514114514,mx=-114514114514;
			for(int k=1;k<=n;k++)
			{
				mn=min(mn,a[k][i]+a[k][j]);
				mx=max(mx,a[k][i]+a[k][j]);
			}
			ans+=mn+mx;
			if(i!=j)ans+=mn+mx;
		}
	}
	cout<<ans;
}
inline void run2()
{
	int ans=0,mul=2*m;
	for(int i=1;i<=m;i++)ans+=mul*(a[1][i]+a[2][i]);
	cout<<ans;
}
signed main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	int opt=check();
	if(n*n*m<=1e9)run1();
	else if(opt==2)run2();
	else run1();
	return 0;
}

