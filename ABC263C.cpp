//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=15;
int n,m;
int st[N],top;
inline void dfs(int step,int last)
{
	if(step==m+1)
	{
		for(int i=1;i<=top;i++)cout<<st[i]<<' ';
		cout<<'\n';
	}
	for(int i=last+1;i<=n;i++)
	{
		st[++top]=i;
		dfs(step+1,i);
		top--;
	}
}
signed main()
{
	cin>>m>>n;
	dfs(1,0);
	return 0;
}

