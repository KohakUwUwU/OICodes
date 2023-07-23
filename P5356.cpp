#include<bits/stdc++.h>
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#define INF 123456789
#define N (int)1e5+1
using namespace std;
int opt,l,r,k,n,m,sz;
int a[N],b[N],pos[N],lb[20000],rb[20000],tag[20000];
#define mn(i) b[lb[i]]
#define mx(i) b[rb[i]]
//char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
inline int getmin(int x,int y)
{
	int ans=INF,posx=pos[x],posy=pos[y];
	if(posx==posy)
	{
		for(int i=x;i<=y;i++)ans=min(ans,a[i]+tag[posx]);
		return ans;
	}
	for(int i=x;i<=rb[posx];i++)ans=min(ans,a[i]+tag[posx]);
	for(int i=posx+1;i<posy;i++)ans=min(ans,mn(i)+tag[i]);
	for(int i=lb[posy];i<=y;i++)ans=min(ans,a[i]+tag[posy]);
	return ans;
}
inline int getmax(int x,int y)
{
	int ans=-INF,posx=pos[x],posy=pos[y];
	if(posx==posy)
	{
		for(int i=x;i<=y;i++)ans=max(ans,a[i]+tag[posx]);
		return ans;
	}
	for(int i=x;i<=rb[posx];i++)ans=max(ans,a[i]+tag[posx]);
	for(int i=posx+1;i<posy;i++)ans=max(ans,mx(i)+tag[i]);
	for(int i=lb[posy];i<=y;i++)ans=max(ans,a[i]+tag[posy]);
	return ans;
}
inline int Rank(int x,int y,int d)
{
	int posx=pos[x],posy=pos[y],cnt=0;
	if(posx==posy)
	{
		for(int i=x;i<=y;i++)if(a[i]+tag[posx]<=d)++cnt;
		return cnt;
	}
	for(int i=x;i<=rb[posx];i++)if(a[i]+tag[posx]<=d)++cnt;
	for(int i=lb[posy];i<=y;i++)if(a[i]+tag[posy]<=d)++cnt;
	for(int i=posx+1;i<posy;i++)
	{
		int L=lb[i],R=rb[i],mid;
		if(b[L]+tag[i]>d)continue;
		if(b[R]+tag[i]<=d)
		{
			cnt+=R-L+1;
			continue;
		}
		while(L<R)
		{
			mid=(L+R)/2+1;
			if(b[mid]+tag[i]<=d)L=mid;
			else R=mid-1;
		}
		if(b[L]+tag[i]<=d)cnt+=L-lb[i]+1;
	}
	return cnt;
}
inline int query()
{
	if(k<1||k>r-l+1)return -1;
	int L=getmin(l,r),R=getmax(l,r),ans=-1;
	while(L<=R)
	{
		int mid=(l+r)/2;
		if(Rank(l,r,mid)<k)L=mid+1;
		else R=mid-1,ans=mid;
	}
	return ans;
}
inline void add()
{
	int posx=pos[l],posy=pos[r];
	if(posx==posy)
	{
		for(int i=l;i<=r;i++)a[i]+=k;
		for(int i=lb[posx];i<=rb[posx];i++)b[i]=a[i];
		sort(b+lb[posx],b+rb[posx]);
		return ;
	}
	for(int i=l;i<=rb[posx];i++)a[i]+=k;
	for(int i=lb[posx];i<=rb[posx];i++)b[i]=a[i];
	sort(b+lb[posx],b+rb[posx]);
	for(int i=lb[posy];i<=r;i++)a[i]+=k;
	for(int i=lb[posy];i<=rb[posy];i++)b[i]=a[i];
	sort(b+lb[posy],b+rb[posy]);
	for(int i=posx+1;i<posy;i++)tag[i]+=k;
}
int main()
{
	n=read();m=read();sz=150;
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i],pos[i]=(i-1)/sz+1;
	for(int i=1;i<=n/sz+1;i++)lb[i]=1+(i-1)*sz,rb[i]=i*sz;
	rb[(n-1)/sz]=n;
	for(int i=1;i<=n/sz+1;i++)sort(b+lb[i],b+rb[i]+1);
	for(int i=1;i<=m;i++)
	{
		opt=read();l=read();r=read();k=read();
		if(opt==1)printf("%d\n",query());
		else add();
	}
}
