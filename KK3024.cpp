//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Point
{
	int x,y,z,id,ans;
}q[N];
int n,f[N],bit[N];
int LSB(int i)
{
	return i&-i;
}
void upd(int i,int len)
{
	while(i<n)
	{
		bit[i]=max(bit[i],len);
		i+=LSB(i);
	}
}
int pmq(int i)
{
	int res=0;
	while(i)
	{
		res=max(res,bit[i]);
		i-=LSB(i);
	}
	return res;
}
void add(int i,int val)
{
	while(i<=n)
	{
		bit[i]-=val;
		i+=LSB(i);
	}
}
bool cmpX(const Point&a,const Point&b)
{
	if(a.x!=b.x)return a.x>b.x;
	if(a.y!=b.y)return a.y>b.y;
	return a.z<b.z;
}
bool cmpY(const Point&a,const Point&b)
{
	if(a.y!=b.y)return a.y>b.y;
	if(a.x!=b.x)return a.x>b.x;
	return a.z<b.z;
}
void cross(int l,int r)
{
	int mid=l+r>>1;
	int i=l;
	int bst=0;
	for(int j=mid+1;j<=r;j++)
	{
		while(i<=mid&&q[i].y>q[j].y)
		{
			upd(q[i].z,q[i].ans);
			++i;
		}
		q[j].ans=max(q[j].ans,pmq(q[j].z-1)+1);
	}
	for(--i;i>=l;--i)add(q[i].z,-1);
}
void cdq(int l,int r)
{
	if(l==r)return ;
	int mid=l+r>>1;
	cdq(l,mid);
	sort(q+l,q+mid+1,cmpY);
	sort(q+mid+1,q+1+r,cmpY);
	cross(l,r);
	sort(q+mid+1,q+r+1,cmpX);
	cdq(mid+1,r);
}
signed main()
{
//	freopen("doll.in","r",stdin);
//	freopen("doll.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].x>>q[i].y;
		q[i].z=i;
		q[i].id=i;
	}
	cdq(1,n);
	for(int i=1;i<=n;i++)
	{
		f[q[i].id]=q[i].ans;
	}
	cout<<*max_element(f+1,f+1+n);
	return 0;
}

