//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,a[N],b[N],c[N],maxa[2005][2005],maxb[2005][2005],maxc[2005][2005],mina[2005][2005],minb[2005][2005],minc[2005][2005];
inline void print()
{
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<maxa[i][j]<<' ';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<maxb[i][j]<<' ';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<maxc[i][j]<<' ';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<mina[i][j]<<' ';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<minb[i][j]<<' ';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<minc[i][j]<<' ';
}
inline bool checka1()
{
	int a1=a[1],b1=b[1],c1=c[1];
	bool aa=0,bb=0,cc=0;
	for(int i=1;i<=n;i++)
	{
		if(a1!=a[i])aa=1;
		if(b1!=b[i])bb=1;
		if(c1!=b[i])cc=1;
	}
	if(!aa||!bb||!cc)return true;
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(checka1())
	{
		cout<<0;
		return 0;
	}
	memset(mina,0x3f,sizeof(mina));
	memset(minb,0x3f,sizeof(minb));
	memset(minc,0x3f,sizeof(minc));
	for(int i=1;i<=n;i++)maxa[i][i]=mina[i][i]=a[i];
	for(int i=1;i<=n;i++)maxb[i][i]=minb[i][i]=b[i];
	for(int i=1;i<=n;i++)maxc[i][i]=minc[i][i]=c[i];
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)maxa[i][i+len-1]=max(maxa[i][i+len-2],a[i+len-1]);
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)maxb[i][i+len-1]=max(maxb[i][i+len-2],b[i+len-1]);
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)maxc[i][i+len-1]=max(maxc[i][i+len-2],c[i+len-1]);
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)mina[i][i+len-1]=min(mina[i][i+len-2],a[i+len-1]);
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)minb[i][i+len-1]=min(minb[i][i+len-2],b[i+len-1]);
	for(int len=2;len<=n;len++)for(int i=1;i<=n-len+1;i++)minc[i][i+len-1]=min(minc[i][i+len-2],c[i+len-1]);
	int ans=0;
	int MOD=(1ll<<32);
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			ans=(ans+(maxa[l][r]-mina[l][r])*(maxb[l][r]-minb[l][r])*(maxc[l][r]-minc[l][r]))%MOD;
		}
	}
	cout<<ans;
	return 0;
}

