//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e9+7;
const int Q=3e5+5;
 x[N],xt[N],y[N],yt[N],dx[N],dy[N];
//x,y clr
//xt,yt time
//dx,dy decrease
int cnt[Q];
int xq[Q],yq[Q],xc,yc;
//the query
int h,w,nc,q,t,n,c;
signed main()
{
	scanf("%lld%lld%lld%lld",&h,&w,&nc,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld",&t,&n,&c);
		if(t==1)
		{
			cnt[x[n]]-=w-dx[n];//decrease the initial clr cnt
			dx[n]=0;//reset dx
			for(int j=1;j<=yc;j++)
			{
				cnt[y[yq[j]]]--;//decrease the other
				if(!x[i])dy[yq[j]]++;//add dy
			}
			cnt[c]+=w;//add
			xq[++xc]=n;//record
			x[n]=c;
			xt[n]=i;
		}
		else
		{
			cnt[y[n]]-=h-dy[n];
			dy[n]=0;
			for(int j=1;j<=xc;j++)
			{
				cnt[x[xq[j]]]--;
				if(!y[i])dx[xq[j]]++;
			}
			cnt[c]+=h;
			yq[++yc]=n;
			y[n]=c;
			yt[n]=i;
		}
	}
	for(int i=1;i<=nc;i++)printf("%lld ",cnt[i]);
	return 0;
}

