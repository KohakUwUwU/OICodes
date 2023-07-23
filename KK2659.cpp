//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
int n,m,clr[N],bit[N],id[N];
vector<int> p[N];
inline int lowbit(int x)
{
	return x&-x;
}
inline int psq(int x)
{
	int ans=0;
	while(x)
	{
		ans+=bit[x];
		x-=lowbit(x);
	}
	return ans;
}
inline void add(int pos,int x)
{
	while(pos<=n)
	{
		bit[pos]+=x;
		pos+=lowbit(pos);
	}
}
inline void move(int frm,int to)
{
	for(int i=0;i<p[frm].size();i++)
	{
		int pos=p[frm][i];
		if(clr[pos-1]==to)add(pos,-1);
		if(clr[pos+1]==to)add(pos+1,-1);
	}
	for(int i=0;i<p[frm].size();i++)
	{
		int pos=p[frm][i];
		clr[pos]=to;
		p[to].push_back(pos);
	}
	p[frm].clear();
}
inline void cleanup()
{
	for(int i=1;i<=n;i++)p[clr[i]].clear(),bit[i]=0;
}
signed main()
{
	freopen("colour.in","r",stdin);
	freopen("colour.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&clr[i]);
		for(int i=1;i<=n;i++)
		{
			p[clr[i]].push_back(i);
			id[clr[i]]=clr[i];
			if(clr[i]!=clr[i-1])add(i,1);
		}
		for(int i=1;i<=m;i++)
		{
			int op,x,y;
			scanf("%lld%lld%lld",&op,&x,&y);
			if(op==2)
			{
				printf("%lld\n",psq(y)-psq(x-1)+(clr[x-1]==clr[x]));
				continue;
			}
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
		cleanup();
	}
	return 0;
}

