#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
#define re register
#define bool char
#define N 100000
const int inf=1e9+1;

int a[N+10],n,m,rt[N+10],sum[N*400+10],ls[N*400+10],rs[N*400+10],tot;
int res1[N+10],res2[N+10],cnt1,cnt2;

inline void up(int t)//子节点更新父亲节点 
{
	sum[t]=sum[ls[t]]+sum[rs[t]];
}

inline void update(int &t,int l,int r,int x,int v)
{
	if(x<l||x>r)return;
	if(!t)t=++tot;
	if(l>=r)
	{
		sum[t]+=v;
		return;
	}
	int mid=(l+r)>>1;
	update(ls[t],l,mid,x,v);update(rs[t],mid+1,r,x,v);up(t);
}

inline void add(int u,int x,int v)
{
	for(re int i=u;i<=n;i+=i&(-i))update(rt[i],0,inf,x,v);
}

inline int query(int l,int r,int k)
{
	if(l>=r)return l;
	int ans1=0,ans2=0;
	for(re int i=1;i<=cnt1;++i)if(res1[i]&&ls[res1[i]])ans1+=sum[ls[res1[i]]];
	for(re int i=1;i<=cnt2;++i)if(res2[i]&&ls[res2[i]])ans2+=sum[ls[res2[i]]];
	int ans=ans2-ans1,mid=(l+r)>>1;
	if(ans>=k)
	{
		for(re int i=1;i<=cnt1;++i)res1[i]=ls[res1[i]];
		for(re int i=1;i<=cnt2;++i)res2[i]=ls[res2[i]];
		return query(l,mid,k);
	}
	else
	{
		for(re int i=1;i<=cnt1;++i)res1[i]=rs[res1[i]];
		for(re int i=1;i<=cnt2;++i)res2[i]=rs[res2[i]];
		return query(mid+1,r,k-ans);
	}
}

inline int ask(int l,int r,int k)
{
	cnt1=cnt2=0;
	for(re int i=l-1;i;i-=i&(-i))res1[++cnt1]=rt[i];
	for(re int i=r;i;i-=i&(-i))res2[++cnt2]=rt[i];
	return query(0,inf,k);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		add(i,a[i],1);
	}
//	puts("rt[i]:");for(re int i=1;i<=n;++i)printf("%d ",rt[i]);puts("");system("pause");
//	for(re int i=1;i<=n;++i)printf("%d ",ask(i,i,1));puts("");system("pause");
	char ch;int x,y,z;
	while(m--)
	{
		for(ch=getchar();(ch!='Q')&&(ch!='C');ch=getchar());
		if(ch=='C')
		{
			scanf("%d%d",&x,&y);
			add(x,a[x],-1);
			a[x]=y;
			add(x,y,1);
		}
		else if(ch=='Q')
		{
			scanf("%d%d%d",&x,&y,&z);
			printf("%d\n",ask(x,y,z));
		}
	}
	return 0;
}

