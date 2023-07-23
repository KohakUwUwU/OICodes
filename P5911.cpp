//TEmPTaTiON
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
struct Team
{
	int t,w;
}m[32],g[70000];
int f[70000],maxw,n;
inline void recovery(int k)
{
	f[k]=inf;
}
signed main()
{
	cin>>maxw>>n;
	for(int i=1;i<=n;i++)cin>>m[i].t>>m[i].w;
	int t=(1<<n)-1;
	for(int i=1;i<=t;i++)for(int j=1;j<=n;j++)if ((i>>(j-1)&1)==1)g[i].t=max(g[i].t,m[j].t),g[i].w+=m[j].w;
	for(int S=1;S<=t;S++)
	{
		recovery(S);
		for(int S1=S;S1!=0;S1=(S1-1)&S)//Ã¶¾Ù×Ó¼¯
		{
			int S2=S^S1;
			if (g[S1].w<=maxw)f[S]=min(f[S],f[S2]+g[S1].t);
		}
	}
	cout<<f[t];
}
