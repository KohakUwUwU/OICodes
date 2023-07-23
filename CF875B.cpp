//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+5;
int n;
int a[N],bit[N];
inline int lowbit(int t)
{
	return t&-t;
}
inline void add(int t)
{
	while(t<=n)
	{
		bit[t]+=1;
		t+=lowbit(t);
	}
}
inline int query(int t)
{
	int ans=0;
	while(t)
	{
		ans+=bit[t];
		t-=lowbit(t);
	}
	return ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=n+1-a[i];
	cout<<1<<' ';
	int last=0;
	for(int i=1;i<=n;i++)
	{
		add(a[i]);
		for(int j=20;j>=0;j--)
		{
			if(last+(1<<j)>n)continue;
			if(last+(1<<j)==query(last+(1<<j)))last+=(1<<j);
		}
		cout<<i-last+1<<' ';
	}
	return 0;
}

