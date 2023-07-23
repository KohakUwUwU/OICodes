#include<iostream>
#include<vector>
const int N=5e5+5;
using namespace std;
vector<int> b,c;
struct Q
{
	int l,r;
};
struct R
{
	int k,v;
};
int n,m,a[N],qt,rt,seg[N*4],tmg[N],ans[N];
Q q[N];
R re[N];
inline void build(int k,int l,int r)
{
	if(l==r)
	{
		seg[k]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1+1,mid+1,r);
	seg[k]=seg[k<<1]+seg[k<<1+1];
}
inline void query(int k,int l,int r,vector<int> state,vector<int> revise)
{
	vector<int> left,right,prc;//prc process
	vector<int> lrv,rrv;
	left.resize(state.size());
	right.resize(state.size());
	lrv.resize(revise.size());
	rrv.resize(revise.size());
	int siz=state.size(),mid=(l+r)>>1,leftt=0,rightt=0,prct=0,lrvt=0,rrvt=0;
	for(int i=0;i<siz;i++)
	{
		Q* p=&q[state[i]];
		if(p->l<=l&&r<=p->r)
		{
			ans[state[i]]=seg[k];
			prc[prct]=state[i];
			prct++;
			continue;
		}
		if(p->l>mid)
		{
			left[leftt]=state[i];
			leftt++;
		}
		if(p->r<=mid)
		{
			right[rightt]=state[i];
			rightt++;
		}
	}
	int curre=0,revsuf=0;
	for(int prcr=0;prcr<prc.size();prcr++)
	{
		int curprc=prc[prcr];//线段上第几号询问 
		if(tmg[curprc]>revise[curre])
		{
			while(tmg[curprc]>revise[curre]&&curre+1!=revise.size())
			{
				curre++;
				revsuf+=revise[curre];
				if(re[revise[curre]].k<=mid)lrv[++lrvt]=revise[curre];
				else rrv[++rrvt]=revise[curre];
			}
		}
		ans[curprc]+=revsuf;
	}
	while(curre+1!=revise.size())
	{
		if(re[revise[curre]].k<=mid)lrv[++lrvt]=revise[curre];
		else rrv[++rrvt]=revise[curre];
	}
	if(l!=r)
	{
		if(leftt>0)query(k<<1,l,mid,left,lrv);
		if(rightt>0)query(k<<1+1,mid+1,r,right,rrv);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	build(0,0,n-1);
	for(int i=0;i<m;i++)
	{
		int a,b1,c1;
		cin>>a>>b1>>c1;
		if(a==1)
		{
			re[rt].k=b1;
			re[rt].v=c1;
			++rt;
		}
		else
		{
			++qt;//记住只有qt从1开始 
			q[qt].l=b1;
			q[qt].r=c1;
			tmg[qt]=rt;//记录时间戳 
		}
	}
	b.resize(qt);
	c.resize(rt);
	for(int i=0;i<qt;i++)b[i]=i;
	for(int i=1;i<=rt;i++)c[i]=i;
	query(0,0,n-1,b,c);
}
