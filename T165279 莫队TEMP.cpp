#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,x,y,pos,ans;
}q[500001];
int n,m;
int rl[500001],rr[500001];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int szx,szy,cur;
int l=1,r=0,u=1,d=0;
inline bool cmp(node x,node y)
{
	if(x.l/szx!=y.l/szx)return x.l<y.l;
	else if(x.x/szy!=y.x/szy)return x.x>y.x;
	else if(x.r!=y.r)return x.r<y.r;
	else return x.y>y.y;
}
inline bool outi(node x,node y)
{
	return x.pos<y.pos;
}
inline void work(){
    for(int i=1;i<=m;i++)
	{
        while(q[i].y>r)
        {
        	r++;
			for(int curx=u;curx<=d;curx++)if(curx>=rl[r]&&curx<=rr[r])cur++;
		}
        while(q[i].y<r)
        {
			for(int curx=u;curx<=d;curx++)if(curx>=rl[r]&&curx<=rr[r])cur--;
			r--;
		}
        while(q[i].x>l)
        {
        	for(int curx=u;curx<=d;curx++)if(curx>=rl[r]&&curx<=rr[r])cur--;
			l++;
		}
        while(q[i].x<l)
        {
        	l--;
			for(int curx=u;curx<=d;curx++)if(curx>=rl[r]&&curx<=rr[r])cur++;
		}
		while(q[i].l<u)
		{
			u--;
			for(int cury=l;cury<=r;cury++)if(u>=rl[cury]&&u<=rr[cury])cur++;
		}
        while(q[i].l>u)
        {
        	for(int cury=l;cury<=r;cury++)if(u>=rl[cury]&&u<=rr[cury])cur--;
			u++;
		}
        while(q[i].r<d)
        {
        	for(int cury=l;cury<=r;cury++)if(d>=rl[cury]&&d<=rr[cury])cur--;
			d--;
		}
        while(q[i].r>d)
        {
			d++;
			for(int cury=l;cury<=r;cury++)if(d>=rl[cury]&&d<=rr[cury])cur++;
		}
        q[i].ans=cur;
    }
}
int main()
{
//	n=read();
	cin>>n; 
	int maxr=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>rl[i]>>rr[i];
//		rl[i]=read();rr[i]=read();
	}
	m=read();
//	cin>>m;
	szx=sqrt(maxr);
	szy=sqrt(n);
//	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].x=read(),q[i].y=read(),q[i].pos=i;
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r>>q[i].x>>q[i].y,q[i].pos=i;
	sort(q+1,q+1+m,cmp);
	work();
	sort(q+1,q+1+m,outi);
	for(int i=1;i<=m;i++)cout<<q[i].ans;
	return 0;
}
