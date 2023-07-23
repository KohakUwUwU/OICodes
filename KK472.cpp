//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300005;
int n,m,q,rtn2[N],rtn1[N],rtm;
vector<int>s;
struct BST
{
	int size,v,pri,lc,rc;
}t[4*N];
//printf scanf

inline void up(int x){t[x].size=t[t[x].lc].size+t[t[x].rc].size+1;}
inline void zig(int &x){int y=t[x].lc; t[x].lc=t[y].rc;t[y].rc=x;up(x),up(y);x=y;}
inline void zag(int &x){int y=t[x].rc; t[x].rc=t[y].lc;t[y].lc=x;up(x),up(y);x=y;}
inline void Insert(int &x,int v)
{
	if(!x)
	{
		x=s.back(),s.pop_back();
		t[x]=(BST){1,v,rand()*rand(),0,0};
		return;
	}
	t[x].size++;
	Insert(t[x].rc,v);
	if(t[t[x].rc].pri>t[x].pri)zag(x);
}
inline void Insert2(int &x,int v)
{
	if(!x)
	{
		x=s.back(),s.pop_back();
		t[x]=(BST){1,v,rand()*rand(),0,0};
		return;
	}
	t[x].size++;
	if(v<t[x].v)
	{
		Insert2(t[x].lc,v);
		if(t[t[x].lc].pri>t[x].pri)zig(x);
	}
	else
	{
		Insert2(t[x].rc,v);
		if(t[t[x].rc].pri>t[x].pri)zag(x);
	}
}
inline void Delete(int &x,int k)
{
	if(t[t[x].lc].size+1==k)
	{
		if(!t[x].lc||!t[x].rc)s.push_back(x),x=t[x].lc+t[x].rc;
		else if(t[t[x].lc].pri>t[t[x].rc].pri)zig(x),Delete(x,k);
		else zag(x),Delete(x,k);
		return;
	}
	t[x].size--;
	if(t[t[x].lc].size+1>k)Delete(t[x].lc,k);
	else Delete(t[x].rc,k-t[t[x].lc].size-1);
}
inline int ask_pre(int x,int v,int res)
{
	if(!x)return res;
	else if(v==t[x].v)return res+t[t[x].lc].size+1;
	else if(v<t[x].v)return ask_pre(t[x].lc,v,res);
	else return ask_pre(t[x].rc,v,res+t[t[x].lc].size+1);
}
inline int ask_rank(int x,int k)
{
	while(t[t[x].lc].size+1!=k)
	{
		if(t[t[x].lc].size+1>k)x=t[x].lc;
		else k-=t[t[x].lc].size+1,x=t[x].rc;
	}
	return t[x].v;
}
inline void init()
{
	for(int i=m+q*3;i>=1;i--)s.push_back(i);
	for(int i=m;i<=(int)m*(int)n;i+=(int)m)Insert(rtm,i);
}
signed main()
{
	srand((int)time(0));
	freopen("phalanx.in","r",stdin);
	freopen("phalanx.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&q);
	init();
	for(int i=1,x,y;i<=q;i++)
	{
		int p,temp;
		scanf("%lld %lld",&x,&y);
		if(m-1-t[rtn1[x]].size>=y)
		{
			int l=1,r=m-1,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				int temp=mid-ask_pre(rtn1[x],mid,0);
				if(temp<y)l=mid+1;
				else r=mid;
			}
			Insert2(rtn1[x],l);
			int temp=ask_rank(rtm,x);
			Delete(rtm,x);
			p=((int)x-1)*(int)m+(int)l;
			printf("%lld\n",p);
			Insert(rtm,p),Insert(rtn2[x],temp);
		}
		else if(m-1>=y)y-=m-1-t[rtn1[x]].size,p=ask_rank(rtn2[x],y),Delete(rtn2[x],y),temp=ask_rank(rtm,x),Delete(rtm,x),Insert(rtm,p),printf("%lld\n",p),Insert(rtn2[x],temp);
		else p=ask_rank(rtm,x),Delete(rtm,x),printf("%lld\n",p),Insert(rtm,p);
	}
	return 0;
}
