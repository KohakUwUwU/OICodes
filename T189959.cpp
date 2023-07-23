//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1;
int n,m,s,k,alr,lst[N];
inline int sum(int l,int r)
{
	return r*s+r*k*(r-1)/2-(l-1)*s-(l-1)*k*((l-1)-1)/2;
}
inline int upb(int l,int r,int val)//区间内扔掉数之和为val最多 
{
	
}
inline void dfs(int l,int r)
{
	if(r-l==1)
	{
		int aa,bb;
		cout<<l<<' '<<l<<endl;
		cin>>aa;
		if(aa==0)lst[++alr]=l;
		if(alr==m)return ;
		cout<<r<<' '<<r<<endl;
		cin>>bb;
		if(bb==0)lst[++alr]=r;
		return ;
	}
	int len=r-l+1;
	int mid1=l+(len)/3-1;
	int mid2=l+(len)/3*2-1;
	int ans[4]={};
	cout<<l<<' '<<mid1<<endl;
	cin>>ans[1];
	if(ans[1]!=sum(l,mid1))
	{
		if(l==mid1)
		{
			lst[++alr]=mid1;
		}
		else if(ans[1]==0)
		{
			for(int i=l;i<=mid1;i++)lst[++alr]=i;
		}
		else
		{
			dfs(l,mid1);
		}
	}
	if(alr==m)return ;
	cout<<mid1+1<<' '<<mid2<<endl;
	cin>>ans[2];
	if(ans[2]!=sum(mid1+1,mid2))
	{
		if(mid1+1==mid2)
		{
			lst[++alr]=mid2;
		}
		else if(ans[2]==0)
		{
			for(int i=mid1+1;i<=mid2;i++)lst[++alr]=i;
		}
		else
		{
			dfs(mid1+1,mid2);
		}
	}
	if(alr==m)return ;
	cout<<mid2+1<<' '<<r<<endl;
	cin>>ans[3];
	if(ans[3]!=sum(mid2+1,r))
	{
		if(mid2+1==r)
		{
			lst[++alr]=r;
		}
		else if(ans[3]==0)
		{
			for(int i=mid2+1;i<=r;i++)lst[++alr]=i;
		}
		else
		{
			dfs(mid2+1,r);
		}
	}
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		alr=0;
		memset(lst,0,sizeof(lst));
		cin>>n>>m>>s>>k;
		dfs(1,n);
		cout<<-1<<' ';
		sort(lst+1,lst+1+m);
		for(int i=1;i<=m;i++)cout<<lst[i]<<' ';
		cout<<endl;
	}
	return 0;
}

