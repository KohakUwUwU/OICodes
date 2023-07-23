#include<iostream>
#include<cstring>
using namespace std;
int n,mine[101],path[101][101],vis[101],current[101],output[101],maxx=-1,cur=0;
inline void dfs(int des)
{
	for(int i=des;i<=n;i++)
	{
		if(path[i][des]&&!vis[i])
		{
			vis[i]=1;cur+=mine[i];current[++current[0]]=i;
			dfs(i);
			vis[i]=0;cur-=mine[i];--current[0];
		}
	}
	if(cur>maxx){
		memcpy(output,current,sizeof(current));
		maxx=cur;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mine[i];
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)cin>>path[i][j],path[j][i]=path[i][j];
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;cur+=mine[i];current[++current[0]]=i;
		dfs(i);
		vis[i]=0;cur-=mine[i];--current[0];
	}
	for(int i=1;i<=output[0];i++)cout<<output[i]<<" ";
	cout<<endl<<maxx;
}
