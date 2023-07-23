//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
const int M=405;
int n,m,a[N][M],ballcnt[N],id[N];
//id[i]表示你看到的第i个在程序里实际上是第id[i]个柱子
pair<int,int>output[820000];
int nQ;
inline void Move(int x,int y)
{
	swap(id[x],id[y]);
} 
inline void Ball(int x,int y)
{
	output[++nQ]=make_pair(x,y);
	a[y][++ballcnt[y]]=a[x][ballcnt[x]--];
}
int q[2*M];
inline int Max(int x)
{
	int ans=-1;
	for(int i=1;i<=m;i++)ans=max(ans,a[x][i]);
	return ans;
}
inline void Cut(int x,int y)
{
	for(int i=1;i<=m;i++)q[i]=a[id[x]][i];
	for(int i=1;i<=m;i++)q[i+m]=a[id[y]][i];
	sort(q+1,q+1+2*m);
	int max_x=Max(id[x]),max_y=Max(id[y]);
	if(max_x>max_y)Move(x,y);
	int val_mid=q[m],A=0;
	for(int i=1;i<=m;i++)if(a[id[x]][i]>q[m])A++;
	int z=n;
	while(z==x||z==y)z--;
	int em=n+1;
	for(int i=1;i<=A;i++)Ball(id[z],id[em]);
	for(int i=m;i>=1;i--)
	{
		if(a[id[x]][i]>=val_mid)Ball(id[x],id[z]);
		else Ball(id[x],id[em]);
	}
	for(int i=1;i<=m-A;i++)Ball(id[em],id[x]);
	for(int i=m;i>=1;i--)
	{
		if(a[id[y]][i]>=val_mid)Ball(id[y],id[em]);
		else Ball(id[y],id[x]);
	}
	for(int i=1;i<=m-A;i++)Ball(id[em],id[y]);
	for(int i=1;i<=A;i++)Ball(id[z],id[y]);
	for(int i=1;i<=A;i++)Ball(id[em],id[z]);
}
inline void msort(int l,int r)
{
	if(l==r)return ;
	int mid=l+r>>1;
	msort(l,mid);
	msort(mid+1,r);
	int x=l,y=mid+1;
	while(1)
	{
		cout<<x<<' '<<y<<'\n';
		if(x>mid)if(y>r)break;
		else
		{
			if(y>r)
			{
				if(Max(id[x])<Max(id[y-1]))
				{
					if(x<=mid)Cut(id[x],id[y-1]);
					if(x<=mid)x++;
				}
				else 
				{
					if(x<=mid)Move(x,y-1),Cut(id[x],id[y-1]);
				}
			}
			else
			{
				if(Max(id[x])<Max(id[y]))
				{
					if(x<=mid&&y<=r)Cut(id[x],id[y]);
					if(x<=mid)x++;
				}
				else 
				{
					if(x<=mid&&y<=r)Move(x,y),Cut(id[x],id[y]);
				}
			}
		}
		
	}
	
}
inline void Flush()
{
	cout<<nQ<<"\n";
	for(int i=1;i<=nQ;i++)cout<<output[i].first<<' '<<output[i].second<<'\n';
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n+1;i++)id[i]=i,ballcnt[i]=m;
	msort(1,n);
	Flush();
	return 0;
}
