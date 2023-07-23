//LizPlum
#include<bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;

const int N=1e5+5;
const ld ERR=1e-9;
int n;
ld w;
struct Lines
{
	ld b,k;
}lines[N];
struct Optimal
{
	ld val;
	int cnt;
};
int q[N];
inline ld X(int u,int v)
{
	return (lines[u].b-lines[v].b)/(lines[v].k-lines[u].k);
}
Optimal f[N];
Optimal calc(ld cpu)
{
	f[0]=(Optimal){0,0};
	lines[0]=(Lines){f[0].val+1-cpu,0};
	q[1]=0;
	int l=1,r=2;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<-1.0/i)++l;
		int j=q[l];
		f[i]=(Optimal){f[j].val+1-cpu+j*(-1.0/i),f[j].cnt+1};
		lines[i]=(Lines){f[i].val+1-cpu,i};
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))--r;
		q[r++]=i;
	}
	return f[n];
}
signed main()
{
	freopen("squid.in","r",stdin);
	freopen("squid.out","w",stdout);
	cin>>n>>w;
	ld low=0,high=1,bstCPU=1;
	while(high-low>ERR)
	{
		ld mid=(low+high)/2.0;
		Optimal opt=calc(mid);
		if(opt.cnt>=w)bstCPU=mid,low=mid;
		else high=mid;
	}
	Optimal opt=calc(bstCPU);
	ld ans=opt.val+w*bstCPU;
	cout<<fixed<<setprecision(4)<<ans<<'\n';
	return 0;
}
