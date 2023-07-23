#include<iostream>
using namespace std;
int fa[10001];
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		fa[find(a)]=find(b);
	}
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b))cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';
	}
}
