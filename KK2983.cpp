//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int P,n,a[N],f[1<<16];
signed main()
{
	freopen("teacher.in","r",stdin);
	freopen("teacher.out","w",stdout);
	cin>>P>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int nMsk=(1<<P);
	for(int i=1;i<=n;i++)f[a[i]]++;
	for(int p=0;p<P;p++)
	{
		for(int msk=0;msk<nMsk;msk++)
		{
			if(((msk>>p)&1)==0)f[msk]+=f[msk^(1<<p)];
		}
	}
	for(int i=1;i<nMsk;i++)cout<<f[i]<<' ';
	return 0;
}

