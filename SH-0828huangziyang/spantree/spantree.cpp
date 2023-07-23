//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=405;
const int MOD=998244353;
int n,l,f[N][N],nlp[N][N];
inline void init()
{
	for(int i=1;i<=400;i++)f[1][i]=1;
	f[2][1]=1;
	for(int i=3;i<=400;i++)(f[i][1]=f[i-1][1]*i)%=MOD;
	for(int i=1;i<=400;i++)
	{
		nlp[i][0]=1;
		for(int j=1;j<=400;j++)nlp[i][j]=nlp[i][j-1]*i;
	}
}
signed main()
{
	freopen("spantree.in","r",stdin);
	freopen("spantree.out","w",stdout);
	cin>>n>>l;
	init();
	for(register int i=2;i<=n;++i)
	{
		for(register int j=2;j<=l;++j)
		{
			for(register int x=1;x<=n;++x)
			{
				for(register int y=1;y<=l;++y)
				{
					(f[i][j]+=f[x-1][y]*f[i-x][y]*nlp[l-y+1][(x-1)*(i-1)])%=MOD;
				}
			}
		}
	}
	cout<<f[n][l];
	return 0;
}
