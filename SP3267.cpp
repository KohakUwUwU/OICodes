#include<bits/stdc++.h>
#define N (int)1e6+5
#define R register
using namespace std;
struct node
{
	int l,r,ans,p;
}f[N];
int n,m,sz,a[N],bin[N],answer[N],pos[N];
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void print(int x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
inline bool cmp(const node& x,const node& y)
{
	return pos[x.l]!=pos[y.l]?x.l<y.l:((pos[x.l]&1)?x.r>y.r:x.r<y.r);
}
int main()
{
	n=read();sz=sqrt(n);
	for(R int i=1;i<=1000000;i++)pos[i]=i/sz;
	for(R int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(R int i=1;i<=m;i++)f[i].l=read(),f[i].r=read(),f[i].p=i;
	sort(f+1,f+1+m,cmp);
	R int l=1,r=0,ans=0;
	for(R int i=1;i<=m;i++)
	{
		while(f[i].l<l)ans+=++bin[a[--l]]==1;
		while(f[i].r>r)ans+=++bin[a[++r]]==1;
		while(f[i].l>l)ans-=bin[a[l++]]--==1;
		while(f[i].r<r)ans-=bin[a[r--]]--==1;
		answer[f[i].p]=ans;
	}
	for(R int i=1;i<=m;i++)print(answer[i]),*O++='\n';
	fwrite(obuf,O-obuf,1,stdout);
}
