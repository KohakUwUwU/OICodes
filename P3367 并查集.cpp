#include<iostream>
#define N (int)1e4+5
using namespace std;
int n,m;
int fa[N];
inline int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	while(m--)
	{
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==2)
		{
			if(find(x)==find(y))cout<<"Y"<<'\n';
			else cout<<"N"<<'\n';
		}
		else fa[find(x)]=find(y);
	}
}
