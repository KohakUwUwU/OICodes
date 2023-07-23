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

const int N=1445;
struct Segment
{
	int l,r,len,val,tag;
	//今儿的tag是改成懒和标的max 
}t[N<<2];
int n;
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r;t[p].len=r-l+1;
//	cout<<p<<' '<<t[p].l<<' '<<t[p].r<<'\n';
	if(l==r)return ;
	int mid=l+r>>1;
	build(l,mid,p*2);build(mid+1,r,p*2+1);
}
inline void PushDown(int p)
{
	t[p*2].tag+=t[p].tag;
	t[p*2+1].tag+=t[p].tag;
	t[p*2].val+=t[p*2].len*t[p].tag;
	t[p*2+1].val+=t[p*2+1].len*t[p].tag;
	t[p*2].tag=0;
}
inline void Change(int l,int r,int x,int y,int val,int p)
{
//	cout<<"p="<<p<<'\n';
	PushDown(p);
//	cout<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if(x<=l&&r<=y)
	{
		t[p].tag=val,t[p].val+=val*t[p].len;
//		cout<<"覆盖"<<p<<' '<<t[p].val<<' '<<t[p].tag<<'\n';
		return ;
	}
	if(r<x||y<l)
	{
//		cout<<'t'<<endl;
		return ;
	}
	int mid=l+r>>1;
	Change(l,mid,x,y,val,p*2);Change(mid+1,r,x,y,val,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline int Query(int l,int r,int x,int y,int val,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return -114514;
	int mid=l+r>>1;
	return max(Query(l,mid,x,y,val,p*2),Query(mid+1,r,x,y,val,p*2+1));
}
inline void Output()
{
	for(int i=1;i<=1000;i++)cout<<t[i].val<<' ';
	cout<<'\n';
}
signed main()
{
//	freopen("clans.in","r",stdin);
//	freopen("clans.out","w",stdout);
	n=read();
	build(1,1440,1);
	for(int i=1,rm=0,r;i<=n;i++)
	{
		string str;
		cin>>str>>r;
		int be=((str[0]-'0')*10+(str[1]-'0'))*60+(str[3]-'0')*10+(str[4]-'0');
		int ed=((str[6]-'0')*10+(str[7]-'0'))*60+(str[9]-'0')*10+(str[10]-'0');
//		cout<<be<<' '<<ed<<'\n';
		Change(1,1440,be,ed,r,1);
//		Output();
		rm=max(rm,Query(1,1440,be,ed,r,1));
		cout<<rm<<'\n';
	}
	return 0;
}

