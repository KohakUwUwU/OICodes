//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define db long double
using namespace std;
//printf scanf

const int N=5e4+5;
struct Lines
{
	db b,k;
}lines[N];
int n;
int ax[N],ay[N],bx[N],by[N];
inline void convert(int i)
{
	lines[i].k=1.0L*(ay[i]-by[i])/(ax[i]-bx[i]);
	lines[i].b=1.0L*ay[i]-lines[i].k*ax[i];
}
inline bool cmp1(Lines x,Lines y)
{
	return x.k<y.k;
}
inline bool cmp2(Lines x,Lines y)
{
	return x.k>y.k;
}
inline db calc(int i,db y)
{
	return (y-lines[i].b)/lines[i].k;
}
db ans[100003];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%lld%lld%lld%lld",&ax[i],&ay[i],&bx[i],&by[i]),convert(i);
	sort(lines+1,lines+1+n,cmp1);
	int pos=1;
	while(lines[pos].k<0)pos++;
	sort(lines+1,lines+pos,cmp2);
	sort(lines+pos,lines+n+1,cmp2);
	db lb=-1e12,rb=1e12;
//	for(int i=1;i<=n;i++)cout<<lines[i].k<<' '<<lines[i].b<<'\n';
	while(rb-lb>=1e-7)
	{
//		cout<<rb<<' '<<lb<<'\n';
		bool b=0;
		db mid=(lb+rb)/2;
		for(int i=1;i<=n;i++)ans[i]=calc(i,mid);
		for(int i=2;i<=n;i++)
		{
			if(ans[i-1]>=ans[i])
			{
				b=1;
				lb=mid;
				break;
			}
		}
		if(!b)rb=mid;
	}
	cout<<fixed<<setprecision(8)<<lb;
	return 0;
}

