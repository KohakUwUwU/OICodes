//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct node
{
	int l,r,val;
	int sz,fac;
	bool exist;
}tzy[N];
int cnt,root;
inline void newnode(int &now,int val)
{
	tzy[now=++cnt].val=val;
	tzy[now].sz=tzy[now].fac=1;
	tzy[now].exist=true;
}
vector<int> v;
inline void ldr(int now)
{
	if(!now)return ;
	ldr(tzy[now].l);
	if(tzy[now].exist)
		v.push_back(now);
	ldr(tzy[now].r);
}
inline void lift(int l,int r,int &now)
{
	if(l==r)
	{
		now=v[l];
		tzy[now].l=tzy[now].r=0;
		tzy[now].sz=tzy[now].fac=1;
		return ;
	}
	int mid=l+r>>1;
	while(mid&&l<mid&&tzy[v[mid]].val==tzy[v[mid-1]].val)
		mid--;
	now=v[mid];
	if(l<mid)lift(l,mid-1,tzy[now].l);
	else tzy[now].l=0;
	lift(mid+1,r,tzy[now].r);
	tzy[now].sz=tzy[tzy[now].l].sz+tzy[tzy[now].r].sz+1;
	tzy[now].fac=tzy[tzy[now].l].fac+tzy[tzy[now].r].fac+1;
}
inline void rebuild(int &now)
{
	v.clear();
	ldr(now);
	if(v.empty())
	{
		now=0;
		return ;
	}
	lift(0,v.size()-1,now);
}
inline bool imbalance(int now)
{
	if(max(tzy[tzy[now].l].sz,tzy[tzy[now].r].sz)>tzy[now].sz*0.75
		||tzy[now].sz-tzy[now].fac>tzy[now].sz*0.3)
		return true;
	return false;
}
inline void update(int now,int end)
{
	if(!now) return ;
	if(tzy[end].val<tzy[now].val)
		update(tzy[now].l,end);
	else update(tzy[now].r,end);
	tzy[now].sz=tzy[tzy[now].l].sz+tzy[tzy[now].r].sz+1;
}
inline void check(int &now,int end)
{
	if(now==end)return ;
	if(imbalance(now))
	{
		rebuild(now);
		update(root,now);
		return ;
	}
	if(tzy[end].val<tzy[now].val)check(tzy[now].l,end);
	else check(tzy[now].r,end);
}
inline void Insert(int &now,int val)
{
	if(!now)
	{
		newnode(now,val);
		check(root,now);
		return ;
	}
	tzy[now].sz++;
	tzy[now].fac++;
	if(val<tzy[now].val)Insert(tzy[now].l,val);
	else Insert(tzy[now].r,val);
}
inline void del(int now,int val)
{
	if(tzy[now].exist&&tzy[now].val==val)
	{
		tzy[now].exist=false;
		tzy[now].fac--;
		check(root,now);
		return ;
	}
	tzy[now].fac--;
	if(val<tzy[now].val)del(tzy[now].l,val);
	else del(tzy[now].r,val);
}
inline int getrank(int val)
{
	int now=root,rank=1;
	while(now)
	{
		if(val<=tzy[now].val)
			now=tzy[now].l;
		else
		{
			rank+=tzy[now].exist+tzy[tzy[now].l].fac;
			now=tzy[now].r;
		} 
	}
	return rank;
}
inline int getnum(int rank)
{
	int now=root;
	while(now)
	{
		if(tzy[now].exist&&tzy[tzy[now].l].fac+tzy[now].exist==rank)
			break;
		else if(tzy[tzy[now].l].fac>=rank)
			now=tzy[now].l;
		else
		{
			rank-=tzy[tzy[now].l].fac+tzy[now].exist;
			now=tzy[now].r;
		}
	}
	return tzy[now].val;
}
signed main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int opt,x;
		scanf("%lld%lld",&opt,&x);
		switch(opt)
		{
		case 1:
			Insert(root,x);
			break;
		case 2:
			del(root,x);
			break;
		case 3:
			printf("%lld\n",getrank(x));
			break;
		case 4:
			printf("%lld\n",getnum(x));
			break;
		case 5:
			printf("%lld\n",getnum(getrank(x)-1));
			break;
		case 6:
			printf("%lld\n",getnum(getrank(x+1)));
			break;
		}
	}
	return 0;
}