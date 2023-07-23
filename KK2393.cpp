//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e4+5;
struct HJT
{
	int l,r,val;
}hjt[N*50];
int n,m,cnt,col[N];
inline void Insert(int l,int r,int pre,int&now,int&pos)
{
	hjt[now=++cnt]=hjt[pre];
	hjt[]
	if(l==r)
	{
		hjt[now].val=col[pos];
		return ;
	}
	int mid=l+r>>1;
	if(pos)
}
inline int query(int l,int r,int now,int pow)
{
	
}
inline void modify(int l,int r,int pre,int&now,int&pos,int&num)
{
	
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&col[i]),Insert(col[i],i)
	for(int i=1;i<=m;i++)
	{
		char opt,x,y;
		scanf("%c%lld%lld",&opt,&x,&y);
		switch(opt)
		{
		case 'Q':
			printf("%lld",query(1,n,))
		}
	}
	return 0;
}

