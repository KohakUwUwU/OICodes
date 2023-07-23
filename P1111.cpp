#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,t;
}c[100001];
int n,m,fa[1001];
inline bool cmp(node x,node y)
{
	return x.t<y.t;
}
inline int Find(int x)
{
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline void Merge(int x,int y)
{
	fa[Find(x)]=Find(y);
}
inline bool judge()
{
	int x=Find(1);
	for(int i=2;i<=n;i++)if(Find(i)!=x)return false;
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>c[i].x>>c[i].y>>c[i].t;
	sort(c,c+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++)
	{
		Merge(c[i].x,c[i].y);
		if(judge())
		{
			cout<<c[i].t;
			return 0;
		}
	}
	cout<<-1;
}
