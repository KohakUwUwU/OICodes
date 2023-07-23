#include<iostream>
#define N (int)5e5+5
using namespace std;
int n,m,a[N],t[N];
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
inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int k,int v)
{
	while(k<=n)
	{
		t[k]+=v;
		k+=lowbit(k);
	}
}
inline int pre(int k)
{
	int sum=0;
	while(k)
	{
		sum+=t[k];
		k-=lowbit(k);
	}
	return sum;
}
inline int sum(int l,int r)
{
	return pre(r)-pre(l-1);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();t[i]+=a[i];
		int j=i+lowbit(i);
		if(j<=n)t[j]+=t[i];
	}
	for(int i=1;i<=4;i++)cout<<t[i]<<' ';
	for(int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)add(x,y);
		else printf("%d\n",sum(x,y));
	}
	return 0;
}
