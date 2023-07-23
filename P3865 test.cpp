//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,f[N][20],lg2[N];
inline void init()
{
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
			if(j+(1<<i)-1<=n)
				f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	int mul=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i>mul)
		{
			mul*=2;
			cnt++;
		}
		lg2[i]=cnt;
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>f[i][0];
	init();
	for(int i=1;i<=m;i++)
	{
		int l,r,len;
		cin>>l>>r;
		len=r-l+1;
		cout<<max(f[l][lg2[len]],f[r-(1<<lg2[len])+1][lg2[len]])<<'\n';
	}
	return 0;
}

