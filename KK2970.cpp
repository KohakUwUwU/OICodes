//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=20;
int P,f[1<<N];
signed main()
{
	freopen("superset.in","r",stdin);
	freopen("superset.out","w",stdout);
	cin>>P;
	int nMsk=(1<<P);
	for(int msk=0;msk<nMsk;msk++)cin>>f[msk];
	for(int p=0;p<P;p++)
	{
		for(int msk=0;msk<nMsk;msk++)
		{
			if(((msk>>p)&1)==0)
			{
				f[msk]+=f[msk^(1<<p)];
			}
		}
	}
	int sum=0;
	for(int msk=0;msk<nMsk;msk++)sum^=f[msk];
	cout<<sum;
	return 0;
}

