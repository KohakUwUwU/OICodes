//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=105;
int x[N],n,f[N];
signed main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	while(cin>>x[n+1])n++;
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(x[j]<x[i])f[i]=max(f[i],f[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}

