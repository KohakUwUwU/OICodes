#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,q;
string str;
int query[N][5];
struct node
{
	int p,l,t;//指针，长度，时间戳 
}con[N][5];
int cnt[N];
int f[N][21],dep[N],t[N][21],len[N];
int vis[N];
inline int getInt(int st,int ed)
{
	int s;
	for(int i=st;i<=ed;i++)s=s*10+st[i]-'0';
	return s;
}
inline void dfs(int x,int fa,int rin,int tm)
{
	f[x][0]=fa;//维护祖先 
	len[x]=rin+len[fa];//维护长度前缀和 
	t[x][0]=max(t[fa][0],);//维护时间
	dep[x]=dep[x]+dep[fa]+1;//维护节点深度 
	for(int i=1;i<=cnt[x];i++)
	{
		if(con[x][i].p==fa)continue;
		dfs(con[x][i].p,x,con[x][i].l);
	}
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		cin>>str;
		for(int j=0;j<str.length();j++)
		{
			if(str[j]!=' ')continue;
			query[i][++query[i][0]]=getInt(flag,j-1);
			j++;
			flag=j;
		}
		if(query[i][0]==3)
		{
			node x;
			x.t=i;
			x.l=query[i][3];
			x.p=query[i][1];
			con[query[i][2]][++cnt[query[i][2]]]=x;
			x.p=query[i][2];
			con[query[i][1]][++cnt[query[i][1]]]=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[N]&&cnt[N]<=2)dfs(i,0);
	}
}
