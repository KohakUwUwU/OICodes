#include<stdio.h>
#include<algorithm>
#define R register
#define ull unsigned long long
//#include<iostream>
//using namespace std;
int t,n;
struct arm
{
	long long a,b,c,d;
}a[100005];
inline long long read(){
    R char ch=getchar();
	R long long f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return f*x;
}
inline bool cmp(arm x,arm y){return x.a!=y.a?x.a<y.a:x.b<y.b;}
int main()
{
	t=read();
	n=read();
	#define int R int
	for(int i=1;i<=n;i++)a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].d=read();
	std::sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++)cout<<a[i].a<<a[i].b<<a[i].c<<a[i].d<<endl;
//	for(int i=1;i<=n;i++)
//	{
////		cout<<inita<<" "<<initb<<endl;
//		if(st<a[i].a)
//		{
//			inita+=a[i].a-st;
//			st=a[i].a;
//		}
//		if(sp<a[i].b)
//		{
//			initb+=a[i].b-sp;
//			sp=a[i].b;
//		}
//		st+=a[i].c;sp+=a[i].d;
//	}
	long long l=0,r=1000000000,st=-1,sp=-1;
	while(l<r)
	{
		bool state=false;
		int mid=(l+r)>>1;
		int run=mid;
		for(int i=1;i<=n;i++)
		{
			if(run<a[i].a)
			{
				state=true;
				break;
			}
			run+=a[i].c;
		}
		if(state)l=mid+1;
		else r=mid;
//		printf("%d %d %d\n",mid,l,r);
	}
	st=l;
	l=0,r=1000000000;
	while(l<r)
	{
		bool state=false;
		int mid=(l+r)>>1;
		int run=mid;
		for(int i=1;i<=n;i++)
		{
			if(run<a[i].b)
			{
				state=true;
				break;
			}
			run+=a[i].d;
		}
		if(state)l=mid+1;
		else r=mid;
	}
	sp=l;
	printf("%lld %lld",st,sp);
}
