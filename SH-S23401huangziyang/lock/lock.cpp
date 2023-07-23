//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,cnt[15],x[15][N];
inline void run1()
{
	for(int i=1;i<=cnt[1]*2;i++)cout<<x[1][i]<<' ';
}
inline void run2()
{
	int c=0;
	for(int i=1;i<=n;i++)c+=cnt[i];
	for(int i=1;i<=c;i++)cout<<"-1 1 ";
}
signed main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i];
		for(int j=1;j<=cnt[i]*2;j++)cin>>x[i][j];
	}
	if(n==1)run1();
	else if(m==1)run2();
	else
	{
		
	}
	return 0;
}

