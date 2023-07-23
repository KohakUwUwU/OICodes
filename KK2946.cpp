//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+9;
struct Edge
{
	int from,to,dist,col;
}Edges[N],black[N],white[N];
int f[N],n,m,need,sz,black_siz,white_siz;
inline void init(){for(int i=1;i<=n;i++)f[i]=i;sz=n;}
inline int find(int x){return (x==f[x])?x:f[x]=find(f[x]);}
inline void merge(int a,int b){int x=find(a),y=find(b);if(x!=y)sz--,f[x]=y;}
inline bool cmp(const Edge &a,const Edge &b){return a.dist<b.dist;}
inline int kruskal(int delta)
{
	int res=0,posa=1,posb=1,tot=0;
	while(posa<=white_siz&&posb<=black_siz)
		if(white[posa].dist+delta<=black[posb].dist)Edges[++tot]=white[posa++],Edges[tot].dist+=delta;
		else Edges[++tot]=black[posb++];
	while(posa<=white_siz)Edges[++tot]=white[posa++],Edges[tot].dist+=delta;
	while(posb<=black_siz)Edges[++tot]=black[posb++];
	init();
	for(int i=1;i<=m&&sz!=1;i++)
	{
		const Edge &e=Edges[i];
		if(find(e.from)!=find(e.to))res+=!e.col;
		merge(e.from,e.to);
	}
	return res;
}
signed main()
{
//	freopen("white.in","r",stdin);
//	freopen("white.out","w",stdout);
	cin>>n>>m>>need;
	for(int u,v,w,c,i=1;i<=m;i++)
	{
		cin>>u>>v>>w>>c;u++;v++;
		if(c==0)white[++white_siz]=Edge{u,v,w,c};
		else black[++black_siz]=Edge{u,v,w,c};
	}
	sort(white+1,white+1+white_siz,cmp);
	sort(black+1,black+1+black_siz,cmp);
	int l=-111,r=111,ans=233;
	while(l<=r)
	{
		int mid=(l+r)>>1,tmp=kruskal(mid);
		if(tmp<need)r=mid-1;
		else ans=mid,l=mid+1;
	}
	if(ans==233)abort();
	int posa=1,posb=1,tot=0;
	while(posa<=white_siz&&posb<=black_siz)
		if(white[posa].dist+ans<=black[posb].dist)Edges[++tot]=white[posa++],Edges[tot].dist+=ans;
		else Edges[++tot]=black[posb++];
	while(posa<=white_siz)Edges[++tot]=white[posa++],Edges[tot].dist+=ans;
	while(posb<=black_siz)Edges[++tot]=black[posb++];
	init();ans*=-need;
	for(int i=1;i<=m&&sz!=1;i++){
		const Edge &e=Edges[i];
		if(find(e.from)!=find(e.to))ans+=e.dist;
		merge(e.from,e.to);
	}
	cout<<ans;
	return 0;
}
