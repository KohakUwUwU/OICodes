//TEmPTaTiON
#include<bits/stdc++.h>
using namespace std;

const int N=1e8+5;
int n,q;
int v[N],m,prime[N];
inline void Prime()
{
	for(int i=2;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;
			prime[++m]=i;
		}
		for(int j=1;j<=m;j++)
		{
			if(prime[j]>v[i]||prime[j]*i>n)break;
			v[prime[j]*i]=prime[j];
		}
	}
}
signed main()
{
	scanf("%d%d",&n,&q);
	Prime();
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",prime[x]);
	}
	return 0;
}

