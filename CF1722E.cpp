//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int t,h[N],w[N],f[1005][1005];
signed main()
{
	cin>>t;
	while(t--)
	{
		int n,q;
		memset(f,0,sizeof(f));
		cin>>n>>q;
		for(int i=1;i<=n;i++)cin>>h[i]>>w[i],f[h[i]][w[i]]+=h[i]*w[i];
		for(int i=1;i<=1001;i++)
		{
			for(int j=1;j<=1001;j++)f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}
		for(int i=1;i<=q;i++)
		{
			int hs,ws,hb,wb;
			cin>>hs>>ws>>hb>>wb;
			hs++,ws++,hb--,wb--;
//			cout<<f[hb][wb]<<' '<<f[hs-1][wb]<<' '<<f[hb][ws-1]<<' '<<f[hs-1][hb-1]<<'\n';
			cout<<f[hb][wb]-f[hs-1][wb]-f[hb][ws-1]+f[hs-1][ws-1]<<'\n';
		}
//		for(int i=1;i<=5;i++)
//		{
//			for(int j=1;j<=5;j++)cout<<f[i][j]<<' ';
//			cout<<'\n'; 
//		}
	}
	return 0;
}

