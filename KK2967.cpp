//LizPlum
#include<bits/stdc++.h>
using namespace std;

const int N=1<<20;
int P;
int g[N][21];
signed main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	cin>>P;
	int nMsk=(1<<P);
	for(int msk=0;msk<nMsk;++msk)cin>>g[msk][0];
	for(int p=1;p<=P;++p)
	{
		for(int msk=0;msk<nMsk;++msk)
		{
			g[msk][p]=g[msk][p-1];
			if((msk>>(p-1))&1)g[msk][p]+=g[msk^(1<<(p-1))][p-1];
		}
	}
	long long sum=0;
	for(int msk=0;msk<(1<<P);++msk)sum+=g[msk][P];
	cout<<sum;
	return 0;
}

