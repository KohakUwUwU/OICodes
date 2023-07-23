//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int T,n,m,a[N],b[N],c[N],tb[N<<2],tc[N<<2],tagc[N<<2];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void buildb(int l,int r,int p)
{
	if(l==r)
	{
		tb[p]=b[l];
		return ;
	}
	buildb(l,mid,lc);buildb(mid+1,r,rc);
	tb[p]=tb[lc]+tb[rc];
}
inline void buildc(int l,int r,int p)
{
	if(l==r)
	{
		tc[p]=c[l];
		return ;
	}
	buildc(l,mid,lc);buildc(mid+1,r,rc);
	tc[p]=max(tc[lc],tc[rc]);
}
inline void Addb(int l,int r,int pos,int val,int p)
{
	if(l==r)
	{
		tb[p]+=val;
		return ;
	}
	if(pos<=mid)Addb(l,mid,pos,val,lc);
	else Addb(mid+1,r,pos,val,rc);
	tb[p]=tb[lc]+tb[rc];
}
inline void PushDownc(int p)
{
	tc[lc]+=tagc[p];
	tc[rc]+=tagc[p];
	tagc[lc]+=tagc[p];
	tagc[rc]+=tagc[p];
	tagc[p]=0;
}
inline void Addc(int l,int r,int x,int y,int val,int p)
{
	PushDownc(p);
	if(x<=l&r<=y)
	{
		tagc[p]+=val;
		tc[p]+=val;
		return ;
	}
	if(x>r||y<l)return ;
	Addc(l,mid,x,y,val,lc);
	Addc(mid+1,r,x,y,val,rc);
	tc[p]=max(tc[lc],tc[rc]);
}
inline int Queryb(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return tb[p];
	if(x>r||y<l)return 0;
	return Queryb(l,mid,x,y,lc)+Queryb(mid+1,r,x,y,rc);
}
inline int Queryc(int l,int r,int x,int y,int p)
{
	PushDownc(p);
	if(x<=l&&r<=y)return tc[p];
	if(x>r||y<l)return -1;
	return max(Queryc(l,mid,x,y,lc),Queryc(mid+1,r,x,y,rc));
}
signed main()
{
	freopen("dungeon.in","r",stdin);
	freopen("dungeon.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(tb,0,sizeof(tb));
		memset(tb,0,sizeof(tc));
		memset(tb,0,sizeof(tagc));
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		int sum=0;
		for(int i=n;i>1;i--)
		{
			sum+=b[i];
			c[i-1]+=sum;
		}
		buildb(1,n,1);buildc(1,n,1);
		for(int i=1;i<=m;i++)
		{
			int opt,x,y,delta;
			cin>>opt>>x;
			switch(opt)
			{
			case 1:
				cin>>y;
				delta=y-a[x];
				a[x]+=delta;
				Addc(1,n,x,x,delta,1);
				break;
			case 2:
				cin>>y;
				delta=y-b[x];
				Addb(1,n,x,delta,1);
				if(x>1)Addc(1,n,1,x-1,delta,1);
				break;
			case 3:
				int temp=Queryc(1,n,1,x,1);
				if(x<n)temp-=Queryb(1,n,x+1,n,1);
				cout<<temp<<'\n';
				break;
			}
		}
	}
	return 0;
}

