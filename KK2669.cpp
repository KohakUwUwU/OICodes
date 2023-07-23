//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e6+5;
int n,c[N],x[N],t[N],g[N],q[N],f[N];
struct Line
{
	int b,k;
}lines[N];
inline double X(int u,int v)
{
	return (lines[u].b-lines[v].b)/(lines[v].k-lines[u].k);
}
signed main()
{
	freopen("dorm2.in","r",stdin);
	freopen("dorm2.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=n;i>=1;i--)t[i]=t[i+1]+x[i],g[i]=g[i+1]+x[i]*(n-i+1);
	lines[0]=(Line){g[1]-t[1]*(n+1),t[1]};
	q[1]=0;
	int l=1,r=2;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<i)l++;
		int j=q[l];
		f[i]=f[j]+g[j+1]-g[i]-(t[j+1]-t[i])*(n-i+1)+c[i];
		lines[i]=(Line){f[i]+g[i+1]-t[i+1]*(n+1),t[i+1]};
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))r--;
		q[r++]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}

