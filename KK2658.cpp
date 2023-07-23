//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e6+5;
vector<int> p[N];
int n,m,nC,clr[N],id[N];
inline void move(int frm,int to)
{
	for(int i=0;i<p[frm].size();i++)
	{
		int pos=p[frm][i];
		nC-=(clr[pos-1]==to);
		nC-=(clr[pos+1]==to);
	}
	for(int i=0;i<p[frm].size();i++)
	{
		int pos=p[frm][i];
		clr[pos]=to;
		p[to].push_back(pos);
	}
	p[frm].clear();
}
inline void solve()
{
	for(int i=1;i<=n;i++)p[clr[i]].push_back(i);
	for(int i=1;i<=n;i++)nC+=(clr[i]!=clr[i-1]);
	for(int i=1;i<=n;i++)id[clr[i]]=clr[i];
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%lld",&op);
		if(op==2)
		{
			printf("%lld\n",nC);
			continue;
		}
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(id[x]==id[y])continue;
		if(p[id[x]].size()>p[id[y]].size())
		{
			move(id[y],id[x]);
			id[y]=id[x];
			id[x]=0;
		}
		else
		{
			move(id[x],id[y]);
			id[x]=0;
		}
	}
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&clr[i]);
	solve();
	return 0;
}

