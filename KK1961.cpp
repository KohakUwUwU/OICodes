#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[200003],s[200003];
int d[200003],d1[200003];
void dfs(int x,int fa,int le)
{
	d[x]=d[fa]+le;
	for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa)dfs(e[x][i],x,s[x][i]);
	return ;
}
void dfs1(int x,int fa,int le)
{
	d1[x]=d1[fa]+le;
	for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa)dfs1(e[x][i],x,s[x][i]);
	return ;
}
signed main()
{
	freopen("visit.in","r",stdin);
	freopen("visit.out","w",stdout);
	int n=read();
	for(int i=1,u,v,k; i<n; i++) u=read(),v=read(),k=read(),e[u].push_back(v),e[v].push_back(u),s[u].push_back(k),s[v].push_back(k);
	dfs(1,0,0);
	int x=-1,t=0;
	for(int i=1; i<=n; i++) if(d[i]>t) t=d[i],x=i;
	dfs(x,0,0);
	int y=-1; t=0;
	for(int i=1; i<=n; i++) if(d[i]>t) t=d[i],y=i;
	dfs1(y,0,0);
	int mxl=-1;
	for(int i=1;i<=n;i++)mxl=max(mxl,d[i]);
	t=0;
	for(int i=1;i<=n;i++)t=max(t,min(d[i],d1[i])+mxl);
	printf("%ld\n",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
