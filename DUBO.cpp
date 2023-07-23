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
inline void dfs(int times,int pos)
{
	if(times==4)
	{
		if(pos%12==0)cnt++;
		return ;
	}
	for(int i=1;i<=6;i++)
	{
		dfs(times+1,pos+i);
	}
}
signed main()
{
	dfs(1,0);	
	cout<<cnt;
	return 0;
}

