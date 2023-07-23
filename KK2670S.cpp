//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e6+5;
struct Line
{
	double b,k;
}lines[N];
int n,h[N],x[N],c[N],t[N],rr[N],q[N],f[N];
inline double X(int u,int v)
{
	return (lines[u].b-lines[v].b)/(lines[v].k-lines[u].k);
}
signed main()
{
	freopen("dorm3.in","r",stdin);
	freopen("dorm3solve.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&h[i],&x[i],&c[i]),t[i]=t[i-1]+x[i],rr[i]=rr[i-1]+h[i]*x[i];
	lines[0]=(Line){0,0};
	q[1]=0;
	int l=1,r=2;
	cout<<1;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<(double)h[i])++l;
		int j=q[l];
		f[i]=-h[i]*t[j]+rr[j]+f[j]+c[i]+h[i]*t[i-1]-rr[i-1];
		lines[i]=(Line){f[i]+rr[j],-t[j]};
		while(r-l>=2&&(X(i,q[r-1])<X(q[r-1],q[r-2])))r--;
		q[r++]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}

