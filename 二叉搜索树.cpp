#include<iostream>
using namespace std;
const int INF=2147483647;
struct t
{
	int lc,rc,val;
	int siz,time;
	t()
	{
		lc=0;
		rc=0;
		val=0;
		siz=0;
		time=0;
	}
}tree[5001];
int n,count=0;
inline int find(int& x,int pos,int cnt=0)
{
	if(!pos)return cnt;
	if(x<=tree[pos].val)return find(x,tree[pos].lc,cnt);
	return find(x,tree[pos].rc,cnt+tree[tree[pos].lc].siz+tree[pos].time);
}
inline int ranking(int& x,int pos,int cnt=1)
{
	if(cnt>=x&&cnt<x+tree[pos].time)return tree[pos].val;
	if(x<cnt)return ranking(x,tree[pos].lc,cnt-tree[pos].time);
	return ranking(x,tree[pos].rc,cnt+tree[tree[pos].lc].siz+tree[pos].time);
}
inline int pre(int& x,int pos)
{
	if(!pos)return -INF;
	if(tree[pos].val<x)return max(tree[pos].val,pre(x,tree[pos].rc));
	if(tree[pos].val==x)return pre(x,tree[pos].lc);
	return pre(x,tree[pos].lc);
}
inline int suc(int& x,int pos)
{
	if(!pos)return INF;
	if(tree[pos].val>x)return min(tree[pos].val,suc(x,tree[pos].lc));
	if(tree[pos].val==x)return suc(x,tree[pos].rc);
	return suc(x,tree[pos].rc);
}
inline int insert(int& x,int pos)
{
	if(tree[1].val==0)
	{
		++count;
		tree[1].val=x;
		tree[1].siz=1;
		tree[1].time=1;
	}
	if(x<tree[pos].val)
	{
		if(!tree[pos].lc)
		{
			t ins;
			ins.val=x;
			ins.siz=1;
			ins.time=1;
			tree[++count]=ins;
			tree[pos].lc=count;
		}
		insert(x,tree[pos].lc);
	}
	if(x>tree[pos].val)
	{
		if(!tree[pos].rc)
		{
			t ins;
			ins.val=x;
			ins.siz=1;
			ins.time=1;
			tree[++count]=ins;
			tree[pos].rc=count;
		}
		insert(x,tree[pos].rc);
	}
	if(x==tree[pos].val)tree[pos].time++;
	tree[pos].siz=tree[tree[pos].lc].siz+tree[tree[pos].rc].siz;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		if(tmp==1)cout<<find(tmp2,1)<<'\n';
		if(tmp==2)cout<<ranking(tmp2,1)<<'\n';
		if(tmp==3)cout<<pre(tmp2,1)<<'\n';
		if(tmp==4)cout<<suc(tmp2,1)<<'\n';
		if(tmp==5)insert(tmp2,1);
	}
}
