//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

//f[i]=min(0<=j<i){f[j]+(h[i]-h[j+1])*x[j+1]+...+(h[i]-h[i-1])*x[i-1]}+c[i]
//f[i]=min(0<=j<i){f[j]+h[i]*(x[j+1]+...+x[i-1])-h[j+1]*x[j+1]-...-h[i-1]*x[i-1]}+c[i]
//tΪxǰ׺  rΪh*xǰ׺ 
//f[i]=min(0<=j<i){f[j]+h[i]*(t[i-1]-t[j])-(r[i-1]-r[j])}+c[i]
//                {-h[i]*t[j]+r[j]+f[j]}+c[i]+h[i]*t[i-1]-r[i-1]
//b=r[j]+f[j]
//k=-t[j]
//other=c[i]+h[i]*t[i-1]-r[i-1]
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
	freopen("dorm3.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&h[i],&x[i],&c[i]),t[i]=t[i-1]+x[i],rr[i]=rr[i-1]+h[i]*x[i];
	lines[0]=(Line){0,0};
	q[1]=0;
	int l=1,r=2;
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

