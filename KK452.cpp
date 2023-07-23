//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
int n,a,b,f[N];
signed main()
{
	freopen("steps.in","r",stdin);
	freopen("steps.out","w",stdout);
	cin>>n>>a>>b;
	f[0]=0;
	for(int i=1;i<=n;i++)f[i]=114514114514;
	for(int i=0;i<n;i++)
	{
		f[i+a]=min(f[i+a],f[i]+1);
		f[i+b]=min(f[i+b],f[i]+1);
	}
	if(f[n]==114514114514)cout<<-1;
	else cout<<f[n];
	return 0;
}

