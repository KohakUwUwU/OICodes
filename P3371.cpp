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
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[1000003];
int dis[1000003];
bool vis[1000003];
signed main()
{
    int n=read(),m=read(),s=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1,x,y,z; i<=m; i++) 
    	x=read(),y=read(),z=read(),
    	v[x].push_back(make_pair(y,z));
    dis[s]=0,q.push(make_pair(0,s));
    while(!q.empty())
    {
    	int x=q.top().second;
    	q.pop();
    	if(vis[x]) continue;
    	vis[x]=1;
    	for(pair<int,int> y:v[x]) 
    		if((!vis[y.first])&&dis[y.first]>dis[x]+y.second) 
    			dis[y.first]=dis[x]+y.second,
    			q.push(make_pair(dis[y.first],y.first));
    }
    for(int i=1; i<=n; ++i) 
    	if(dis[i]>1e12) printf("%d ",0x7fffffff);
    	else printf("%lld ",dis[i]);
	return 0;
}

