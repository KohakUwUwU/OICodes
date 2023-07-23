//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Segment
{
	int l,r,ch[2],val,cnt;
}t[1670000];
int cnt=1;
int n,a[N],rt[N],ans[N];
vector<int>G[N];
#define mid (l+r>>1)
inline int New(int p,int lr)
{
	int l=t[p].l,r=t[p].r;
	if(t[p].ch[lr])return t[p].ch[lr];
	else
	{
		t[p].ch[lr]=++cnt;
		if(!lr)t[cnt]=(Segment){l,mid,{0,0},0,0};
		else t[cnt]=(Segment){mid+1,r,{0,0},0,0};
		return cnt;
	}
}
#define lc (New(p,0))
#define rc (New(p,1))
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void Print(int p)
{
	cout<<p<<' '<<t[p].l<<' '<<t[p].r<<' '<<t[p].val<<' '<<t[p].cnt<<'\n';
}
inline void Insert(int l,int r,int pos,int p)
{
	if(l==r)
	{
		t[p].val=pos,t[p].cnt++;
//		Print(p);
		return ;
	}
	if(pos<=mid)Insert(l,mid,pos,lc);
	else Insert(mid+1,r,pos,rc);
	if(t[lc].cnt<t[rc].cnt)
	{
		t[p].cnt=t[rc].cnt;
		t[p].val=t[rc].val;
	}
	else if(t[lc].cnt>t[rc].cnt)
	{
		t[p].cnt=t[lc].cnt;
		t[p].val=t[lc].val;
	}
	else
	{
		t[p].cnt=t[lc].cnt;
		t[p].val=t[lc].val+t[rc].val;
	}
//	Print(p);
}
inline int Merge(int l,int r,int p1,int p2)
{
	if(!p1)return p2;
	if(!p2)return p1;
	if(l==r)
	{
		t[p1].cnt+=t[p2].cnt;
		return p1;
	}
	t[p1].ch[0]=Merge(l,mid,t[p1].ch[0],t[p2].ch[0]);
	t[p1].ch[1]=Merge(mid+1,r,t[p1].ch[1],t[p2].ch[1]);
	if(!t[p1].ch[0])
	{
		t[p1].cnt=t[t[p1].ch[1]].cnt;
		t[p1].val=t[t[p1].ch[1]].val;
	}
	else if(!t[p1].ch[1])
	{
		t[p1].cnt=t[t[p1].ch[0]].cnt;
		t[p1].val=t[t[p1].ch[0]].val;
	}
	else
	{
		int ch0=t[p1].ch[0];
		int ch1=t[p1].ch[1];
		if(t[ch0].cnt<t[ch1].cnt)
		{
			t[p1].val=t[ch0].val;
			t[p1].cnt=t[ch0].cnt;
		}
		else if(t[ch0].cnt>t[ch1].cnt)
		{
			t[p1].val=t[ch1].val;
			t[p1].cnt=t[ch1].cnt;
		}
		else
		{
			t[p1].val=t[ch0].val+t[ch1].val;
			t[p1].cnt=t[ch0].cnt;
		}
	}
//	Print(p1);
	return p1;
}
inline void dfs(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		Merge(1,n,rt[u],rt[v]);
	}
	Insert(1,n,a[u],rt[u]);
	ans[u]=t[rt[u]].val;
//	cout<<u<<' '<<ans[u]<<'\n';
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		rt[i]=++cnt;
		t[rt[i]]=(Segment){1,n,{0,0},0,0};
//		Insert(1,n,a[i],rt[i]);
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}

