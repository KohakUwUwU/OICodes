#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+5;
struct Line
{
	double b,k;
}lines[N];
int n,G,w[N],q[N],f[N],s[N],t[N],H;
inline double X(int u,int v)
{
	return (lines[v].b-lines[u].b)/(lines[u].k-lines[v].k);
}
signed main()
{
	freopen("packing.in","r",stdin);
	freopen("packing.out","w",stdout);
	scanf("%lld%lld",&n,&G);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	lines[0]=(Line){0,0};
	q[1]=0;
	int l=1,r=2;H=G+1;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+w[i],t[i]=s[i]+i;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<t[i])++l;
		int j=q[l];
		f[i]=f[j]+(t[i]-t[j]-H)*(t[i]-t[j]-H);
		lines[i]=(Line){f[i]+t[i]*t[i]+2*H*t[i],-2*t[i]};
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))r--;
		q[r++]=i;
	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	printf("%lld\n",f[n]);
	return 0;
} 
