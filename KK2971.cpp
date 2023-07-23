//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

int P;
int fst[1<<20],snd[1<<20],f[1<<20];
inline void upd(int x,int y)
{
	if(fst[y]<=snd[x])return ;
	snd[x]=fst[y];
	if(snd[x]<=fst[x])return ;
	swap(snd[x],fst[x]);
	if(snd[y]<=snd[x])return ;
	snd[x]=snd[y];
} 
signed main()
{
	freopen("bst.in","r",stdin);
	freopen("bst.out","w",stdout);
	cin>>P;
	int nMsk=(1<<P);
	for(int msk=0;msk<nMsk;msk++)cin>>fst[msk];
	for(int p=0;p<P;p++)
	{
		for(int msk=0;msk<nMsk;msk++)
		{
			if((msk>>p)&1)upd(msk,msk^(1<<p));
		}
	}
	for(int msk=0;msk<nMsk;msk++)f[msk]=fst[msk]+snd[msk];
	for(int k=1;k<nMsk;k++)f[k]=max(f[k],f[k-1]);
	for(int k=1;k<nMsk;k++)cout<<f[k]<<'\n';
	return 0;
}

