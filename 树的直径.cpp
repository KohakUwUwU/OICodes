#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[100003];
int d[100003];
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for(int y:e[x]) if(y!=fa) dfs(y,x);
	return ;
}
signed main()
{
	int n=read();
	for(int i=1,u,v; i<n; i++) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	int x=-1,t=0;
	for(int i=1; i<=n; i++) if(d[i]>t) t=d[i],x=i;
	dfs(x,0);
	int y=-1; t=0;
	for(int i=1; i<=n; i++) if(d[i]>t) t=d[i],y=i;
	//The length is t-16
	printf("%d\n",t-1);
	return 0;
}

