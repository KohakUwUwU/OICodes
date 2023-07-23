//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

const int N=1e5;
struct num
{
	int id,val;
}a[N];
int n,tg[N],id;
inline bool cmp(num x,num y)
{
	return x.val<y.val;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i].val=read();
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int init=-114514;
	for(int i=1;i<=n;i++)
	{
		if(init!=a[i].val)id++;
		tg[a[i].id]=id;
		init=id;
	}
	for(int i=1;i<=n;i++)cout<<tg[i]<<' ';
	return 0;
}

