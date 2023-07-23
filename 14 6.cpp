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

int cnt=0;
inline void dfs(int pos,int remain)
{
	if(remain==0)return ;
	if(pos==4)
	{
		if(remain<=6)cnt++;
		return ;
	}
	for(int i=1;i<=6&&remain>=i;i++)
	{
		dfs(pos+1,remain-1);
	}
}
signed main()
{
	int n=read(),m=read();
	dfs(1,14);	
	cout<<cnt;
	return 0;
}

