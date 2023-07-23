#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
struct Q
{
	int l,r,k,m,t;//left ;; right ;; position of input ;; request mode ;; [revise-num]
}q[maxn];
int n,m,siz;
int res,a[maxn],pos[maxn],ans[maxn];
inline void Add(int p)
{
	res+=a[p];
}
inline void Sub(int p)
{
	res-=a[p];
}
inline bool cmp(Q x,Q y)
{
	if(pos[x.l]==pos[y.l])return x.r<y.r;
	else return pos[x.l]<pos[y.l];
}
int main()
{
	cin>>n>>p;
	siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[i]=i/siz;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].o>>q[i].l>>q[i].r;
		q[i].k=i;
		if(q[i].o!=3)cin>>q[i].t;
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(q[i].l<l)Add(--l);
		while(q[i].r>r)Add(++r);
		while(q[i].l>l)Sub(l++);
		while(q[i].r<r)Sub(r--);
		ans[q[i].k]=res;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
