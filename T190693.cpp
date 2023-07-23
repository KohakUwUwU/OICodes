//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m;string str;
int st[N];int sz;
inline void work1(int v)
{
	if(v+sz>=n)
	{
		sz=n;
		for(int i=1;i<=n;i++)st[i]=n-i+1;
		return ;
	}
	int lo=21;
	int pos=sz+1;
	while(lo>0)
	{
		lo--;
		if(pos-(1<<lo)<=0)continue;
		if((sz-pos+1)+v>=st[pos-(1<<lo)])pos-=(1<<lo);
	}
	for(int i=1;i<=sz-pos+1+v;i++)
	{
		st[pos+(sz-pos+1+v-i)]=i;
		//st[pos]=sz-pos+1+v;
	}
	sz=pos+(sz-pos+1+v)-1;
}
inline void work2(int v)
{
	v=-v;
	sz-=min(sz,v);
}
signed main()
{
	cin>>n>>m>>str;
	for(int i=0;i<n;i++)if(str[i]=='1')st[++sz]=n-i;
	for(int i=1;i<=m;i++)
	{
		int v;
		cin>>v;
		if(v>0)work1(v);
		else work2(v);
		int res=0;
//		for(int i=1;i<=sz;i++)cout<<st[i]<<' ';
//		cout<<'\n';
		int last=st[1],lianxuduan=1;
		for(int i=2;i<=sz;i++)
		{
			if(st[i]+lianxuduan==last)lianxuduan++;
			else
			{
				int u=st[i-1];
				int dddd=u+lianxuduan-1;
				res+=dddd+(u-1);
				last=st[i];
				lianxuduan=1;
			}
		}
		res+=last+(last-lianxuduan);
		cout<<res<<'\n';
	}
	return 0;
}

