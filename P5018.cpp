//#include<bits/stdc++.h>
//#define N 1000005
//#define ull unsigned long long
//using namespace std;
//const ull HASH=2654435769;
//const ull STATE=998989991;
//struct node
//{
//	int val,lc,rc,siz;
//	ull hal,har;
//	node()
//	{
//		val=0;lc=-1;rc=-1;hal=0;har=0;siz=0;
//	}
//}tree[N];
//int n,mxsiz=-1;
//inline void init(int pos)
//{
//	if(pos==-1)return ;
//	init(tree[pos].lc);
//	init(tree[pos].rc);
//	tree[pos].siz=tree[tree[pos].lc].siz+tree[tree[pos].rc].siz+1;
//}
//inline void calc(int pos)
//{
//	if(pos==-1)return ;
//	calc(tree[pos].lc);
//	calc(tree[pos].rc);
//	if(tree[tree[pos].lc].hal==tree[tree[pos].rc].har&&tree[tree[pos].lc].siz==tree[tree[pos].rc].siz)mxsiz=max(mxsiz,tree[pos].siz);
//	tree[pos].hal=tree[pos].val*HASH+tree[tree[pos].lc].hal*HASH*HASH+tree[tree[pos].rc].hal*HASH*HASH*HASH;
//	tree[pos].har=tree[pos].val*HASH+tree[tree[pos].rc].har*HASH*HASH+tree[tree[pos].lc].har*HASH*HASH*HASH;
//	if(tree[pos].rc!=-1)tree[pos].hal+=STATE,tree[pos].har+=STATE*STATE;
//	if(tree[pos].lc!=-1)tree[pos].hal+=STATE*STATE,tree[pos].har+=STATE;
//}
//int main()
//{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)cin>>tree[i].val;
//	for(int i=1;i<=n;i++)cin>>tree[i].lc>>tree[i].rc;
//	init(1);
//	calc(1);
//	cout<<mxsiz;
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int t,a[1000001],l[1000001],r[1000001],i,n,m=1,x;
int dfs(int x,int y)
{
	if(a[x]!=a[y])return 0;
	t+=2;
	if(l[x]==-1){if(r[y]!=-1)return 0;}
	else if(r[y]==-1)return 0;else{int k=dfs(l[x],r[y]);if(k==0)return 0;}
	if(r[x]==-1){if(l[y]!=-1)return 0;}
	else if(l[y]==-1)return 0;else{int k=dfs(r[x],l[y]);if(k==0)return 0;}
	return t;
}
int p(int x)
{
	t=1;
	return dfs(l[x],r[x]);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>l[i]>>r[i];
	for(i=1;i<=n;i++)
	{
		if(l[i]==-1||r[i]==-1)continue;
		x=p(i);
		if(x&&m<x)m=x;
	}
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
