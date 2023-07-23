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
struct Book
{
	int h,w;
}bk[N];
struct Line
{
	int b,k;
}lines[N];
long double X(int u,int v)
{
	return -(long double)(lines[u].b-lines[v].b)/(lines[u].k-lines[v].k);
}
int n,f[N],q[N];
signed main()
{
	freopen("books.in","r",stdin);
	freopen("books.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)bk[i].h=read(),bk[i].w=read();
	lines[0]=(Line){0,bk[1].w};
	q[1]=0;
	int l=1,r=2;
	for(int i=1;i<=n;i++)
	{
		while(r-l>=2&&X(q[l],q[l+1])<bk[i].h)++l;
		int j=q[l];
		f[i]=f[j]+bk[j+1].w*bk[i].h;
		lines[i]=(Line){f[i],bk[i+1].w};
		while(r-l>=2&&X(i,q[r-1])<X(q[r-1],q[r-2]))--r;
		q[r++]=i;
	}
	cout<<f[n];
	return 0;
}

