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

const int N=5e5+5;
struct Line
{
	int b,k;
}lines[N];
long double X(int u,int v)
{
	return -(long double)(lines[u].b-lines[v].b)/(lines[u].k-lines[v].k);
}
int n,m,q[N*2],ans[N*2],x[N*2];
signed main()
{
	freopen("lines.in","r",stdin);
	freopen("lines.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)lines[i].b=read();
	for(int i=1;i<=n;i++)lines[i].k=read();
	for(int i=1;i<=m;i++)x[i]=read();
	int l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))--r;
		q[r++]=i;
	}
	for(int i=1;i<=m;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<x[i])++l;
		int j=q[l];
		ans[i]=lines[j].b+lines[j].k*x[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

