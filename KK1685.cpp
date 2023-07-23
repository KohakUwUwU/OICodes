#include<bits/stdc++.h>
using namespace std;
int n,a,b,mxdep=-1;
vector<int>g[100001];
int vis[100001];
inline int* dfs(int x,int dep)
{
	vis[x]=1;
	int* k0=new int[2];
	k0[0]=x;
	k0[1]=dep;
	for(int i=0;i<g[x].size();i++)
	{
		if(vis[g[x][i]])continue;
		int* k=dfs(g[x][i],dep+1);
		if(k[1]>k0[1])
		{
			k0[0]=k[0];
			k0[1]=k[1];
		}
	}
	return k0;
}
int main()
{
	freopen("diameter.in","r",stdin);
	freopen("diameter.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int *arr=dfs(1,0); 
	memset(vis,0,sizeof(vis));
	int *arr1=dfs(arr[0],0);
	cout<<arr1[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
