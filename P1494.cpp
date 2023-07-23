#include<bits/stdc++.h>
#define N (int)5e4+5
using namespace std;
struct node
{
	int l,r,p;
}f[N];
int n,m,sz,a[N],pos[N],answer[N],bin[N];
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void print(int x)
{
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
	return pos[x.l]!=pos[y.l]?x.l<y.l:(pos[x.l]&1?x.r<y.r:x.r>y.r);
}
inline int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
	n=read(),m=read();sz=sqrt(n);
	for(int i=1;i<N;i++)pos[i]=i/sz;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)f[i].l=read(),f[i].r=read(),f[i].p=i;
	sort(f+1,f+1+m,cmp);
	int l=1,r=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		while(f[i].l<l)ans+=bin[a[--l]]++*2;
		while(f[i].r>r)ans+=bin[a[++r]]++*2;
		while(f[i].l>l)ans-=--bin[a[l++]]*2;
		while(f[i].r<r)ans-=--bin[a[r--]]*2;
		answer[f[i].p]=ans;
	}
	for(int i=1;i<=m;i++)
	{
		if(answer[i]==0)
		{
			printf("0/1\n");
			continue;
		}
		int x=gcd(f[i].r-f[i].l+1,answer[i]);
		printf("%d/%d\n",answer[i]/x,(f[i].r-f[i].l+1)/x);
	}
}
