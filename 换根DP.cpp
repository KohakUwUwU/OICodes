#include<iostream>
#define N 10001
using namespace std;
struct node
{
	int lc,rc,ld,rd,siz,dis,fa;//���ӣ��Һ��ӣ����Ȩ���ұ�Ȩ
	node()
	{
		lc=0;rc=0;siz=0;dis=0;fa=0;
	}
}tree[N];
int n,sum,dp[N];
#define getd(k) ((tree[tree[k].fa].lc==k)?(tree[tree[k].fa].ld):(tree[tree[k].fa].rd))
inline void dfs1(int k)
{
	if(tree[k].lc!=0)dfs1(tree[k].lc);
	if(tree[k].rc!=0)dfs1(tree[k].rc);
	tree[k].siz=tree[tree[k].lc].siz+tree[tree[k].rc].siz+1;
	tree[k].dis=tree[tree[k].lc].siz*tree[k].ld+tree[tree[k].lc].dis+tree[tree[k].rc].siz*tree[k].rd+tree[tree[k].rc].dis;
} 
inline void dfs2(int k)
{
	dp[k]=dp[tree[k].fa]+(n-2*tree[k].siz)*getd(k);sum+=dp[k];
	if(tree[k].lc)dfs2(tree[k].lc);
	if(tree[k].rc)dfs2(tree[k].rc);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>tree[i].lc>>tree[i].rc>>tree[i].ld>>tree[i].rd,tree[tree[i].lc].fa=i,tree[tree[i].rc].fa=i;//����ÿ���ڵ�ĺ����Լ���Ȩ����Ϊ�սڵ�����0 
	dfs1(1);
	sum+=tree[1].dis;dp[1]=tree[1].dis;
	dfs2(tree[1].lc);dfs2(tree[1].rc);
	cout<<sum;
}
//����n���ڵ㣬��1Ϊ�����б�Ȩ�Ķ���������ÿ���ڵ㵽���нڵ����֮��֮�� 
