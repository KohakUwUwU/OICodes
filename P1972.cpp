#include<stdio.h>
#include<algorithm>
#pragma GCC target("avx")
#define N (int)1e6+5
#define R register
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void print(const int& x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
inline int read()
{
	R int s=0;
	R char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
int main()
{
	struct node
	{
		int l,r,p,pos;
		bool operator<(const node& y)const
		{
			return pos!=y.pos?l<y.l:((pos&1)?r>y.r:r<y.r);
		}
	};
	register node f[N];
	register int l=1,r=0,ans=0,n=read(),m,sz=3225,a[N],bin[N],answer[N],i=1;
	for(;i<=n;++i)a[i]=read();
	m=read();
	for(i=1;i<=m;++i)f[i].l=read(),f[i].r=read(),f[i].p=i,f[i].pos=f[i].l/sz;
	std::sort(f+1,f+1+m);
	for(i=1;i<=m;++i)
	{
		while(f[i].l<l)ans+=++bin[a[--l]]==1;
		while(f[i].r>r)ans+=++bin[a[++r]]==1;
		while(f[i].l>l)ans-=bin[a[l++]]--==1;
		while(f[i].r<r)ans-=bin[a[r--]]--==1;
		answer[f[i].p]=ans;
	}
	for(i=1;i<=m;++i)print(answer[i]),*O++='\n';
	fwrite(obuf,O-obuf,1,stdout);
}
