#include<bits/stdc++.h>
#define N 133334
using namespace std;
struct revise
{
	int pos,col;
}rr[N];
struct query
{
	int l,r,t,p,pos;
}q[N];
int n,m,cntR,cntQ,sz,a[N],bin[N],ans[N];
stack<int> mo[N];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
inline bool cmp(query x,query y)
{
	return x.pos!=y.pos?x.pos<y.pos:(x.t!=y.t?(x.pos&1?x.t<y.t:x.t>y.t):((x.pos&1)?(x.r<y.r):(x.r>y.r)));
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		char opt=getchar();
		int aa=read(),bb=read();
		if(opt=='Q')q[++cntQ]=query{aa,bb,cntR,cntQ,0};
		else rr[++cntR]=revise{aa,bb};
	}
	sz=sqrt(cntQ);
	for(int i=1;i<=cntQ;++i)q[i].pos=q[i].l/sz;
	sort(q+1,q+1+cntQ,cmp);
	int l=1,r=0,t=0,cnt=0;
	for(int i=1;i<=cntQ;++i)
	{
		while(t>q[i].t)
		{
			if(--bin[a[rr[t].pos]]==0)if(l<=rr[t].pos&&rr[t].pos<=r)cnt--;
			a[rr[t].pos]=mo[a[rr[t].pos]].top();
			mo[a[rr[t].pos]].pop();
			if(++bin[a[rr[t].pos]]==1)if(l<=rr[t].pos&&rr[t].pos<=r)cnt++;
			--t;
		}
		while(t<q[i].t)
		{
			t++;
			mo[a[rr[t].pos]].push(a[rr[t].pos]);
			if(--bin[a[rr[t].pos]]==0&&l<=rr[t].pos&&rr[t].pos<=r)cnt--;
			a[rr[t].pos]=rr[t].col;
			if(++bin[a[rr[t].pos]]==1&&l<=rr[t].pos&&rr[t].pos<=r)cnt++;
		}
		while(l>q[i].l)cnt-=(--bin[a[--l]]==0);
		while(r<q[i].r)cnt-=(--bin[a[++r]]==0);
		while(l<q[i].l)cnt+=(++bin[a[l++]]==1);
		while(r>q[i].r)cnt+=(++bin[a[r--]]==1);
		ans[q[i].p]=cnt;
	}
	for(int i=1;i<=cntQ;i++)cout<<ans[i]<<'\n';
}
