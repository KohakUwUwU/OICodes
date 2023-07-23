#include<bits/stdc++.h>
#define N (int)5e4+5
using namespace std;
struct query
{
	int l,r,pos,p;
}q[N];
int n,m,k,sz,a[N],pos[N],ans[N],bin[N];
inline bool cmp(query x,query y)
{
	return x.pos!=y.pos?x.pos<y.pos:(x.pos&1?x.r<y.r:x.r>y.r);
}
int main()
{
	cin>>n>>m>>k;sz=sqrt(n);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].p=i,q[i].pos=(q[i].l-1)/sz;
	sort(q+1,q+1+m,cmp);
	int l=1,r=0,as=0;
	for(int i=1;i<=m;i++)
	{
		while(q[i].l<l)as+=2*(bin[a[--l]]++)+1;
		while(q[i].r>r)as+=2*(bin[a[++r]]++)+1;
		while(q[i].l>l)as-=2*(--bin[a[l++]])+1;
		while(q[i].r<r)as-=2*(--bin[a[r--]])+1;
		ans[q[i].p]=as;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
}
