//TEmPTaTiON
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+3,M=3e5+3;
int h,w,c,q,typ[M],pla[M],col[M];
long long ans[M],delhang=0,dellie=0;
bitset<N>hang,lie;
signed main()
{
	cin>>h>>w>>c>>q;
	for(int i=1;i<=q;i++)cin>>typ[i]>>pla[i]>>col[i];
	for(int i=q;i>0;i--)
	{
		if(typ[i]==1)
		{
			if(hang[pla[i]])continue;
			hang[pla[i]]=1;
			ans[col[i]]+=w-dellie;
			delhang++;
		}
		else
		{
			if(lie[pla[i]])continue;
			lie[pla[i]]=1;
			ans[col[i]]+=h-delhang;
			dellie++;
		}
	}
	for(int i=1;i<=c;i++)cout<<ans[i]<<' ';
	return 0;
}

