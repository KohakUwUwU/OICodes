//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,m;
int ans[N],p[N],cnt[N];
struct Q
{
	int spd,id;
}q[N],lmt[N];
bool cmp(Q x,Q y)
{
	return x.spd<y.spd;
}
int root(int x)
{
	if(p[x]==x)return x;
	return p[x]=root(p[x]);
}
void add(int x)
{
	int r=root(x-1);
	p[x]=r;
	cnt[r]+=cnt[x]+1;
	cnt[x]=0;
}
void upd(int &x,int &y)
{
	if(x<y)x=y;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	n--;
	for(int i=1;i<=n;i++)scanf("%lld",&lmt[i].spd),lmt[i].id=i,p[i]=i;
	for(int i=1;i<=m;i++)scanf("%lld",&q[i].spd),q[i].id=i;
	sort(q+1,q+1+m,cmp);
	sort(lmt+1,lmt+1+n,cmp);
	int iL=1;
	for(int iQ=1;iQ<=m;iQ++)
	{
		if(iQ==1)ans[q[iQ].id]=0;
		else ans[q[iQ].id]=ans[q[iQ-1].id];
		while(iL<=n-1&&q[iQ].spd<=lmt[iL].spd)
		{
			add(lmt[iL].id);
			upd(ans[q[iQ].id],cnt[root(lmt[iL].id)]);
			iL++;
		}
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}

