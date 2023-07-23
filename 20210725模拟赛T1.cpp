//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=5e4+5;
struct Line
{
	double b,k;
}l[N];
int n;
double ax[N],ay[N],bx[N],by[N],curX[N];
inline void convert(int i)
{
	l[i].k=(ay[i]-by[i])/(ax[i]-bx[i]);
	l[i].b=ay[i]-l[i].k*ax[i];
}
inline bool cmp(Line x,Line y)
{
	return x.k<y.k;
}
inline bool Dcmp(Line x,Line y)
{
	return x.k>y.k;
}
inline double calc(int id,double y)
{
	return (y-l[id].b)/l[id].k;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&ax[i],&ay[i],&bx[i],&by[i]),convert(i);
	sort(l+1,l+1+n,cmp);
	int tag=1;
	while(tag<=n&&l[tag].k<0)tag++;
	tag--;
	sort(l+1,l+1+tag,Dcmp);
	for(int i=1;i<=n;i++)cout<<l[i].k<<' ';
	cout<<'\n';
	double lb=-1e12,rb=1e12;
	while(rb-lb>1e-7)
	{
		bool b=1;
		double mid=(rb+lb)/2;
		for(int i=1;i<=n;i++)curX[i]=calc(i,mid);
		for(int i=1;i<n;i++)
		{
			if(curX[i]>curX[i+1])
			{
				b=0;
				break;
			}
		}
		if(b)lb=mid;
		else rb=mid;
	}
	cout<<fixed<<setprecision(8)<<lb;
	return 0;
}
