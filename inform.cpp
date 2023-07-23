#include<bits/stdc++.h>
using namespace std;
int n,v,tot;
int ma[5001][5001],pos[5001][2];
struct node
{
	int x,y,val;
}qwq;
struct cmp
{
	bool operator() (node x,node y)
	{
		return x.val>y.val;
	}
};
priority_queue<node,vector<node>,cmp> q;
int fa[5001],sum,meerge;
bool state;
inline int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
inline bool check()
{
	int x=find(1);
	for(int i=2;i<=n;i++)if(find(i)!=x){
		state=false;
		return true;
	}
	state=true;
	return false;
}
int main()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)cin>>pos[i][0]>>pos[i][1];
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
	{
		if(i==j)ma[i][j]=9989899;
		int d=(pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]);
		if(v<d)ma[i][j]=ma[j][i]=v;
		else
		{
			ma[i][j]=ma[j][i]=d;
			qwq.val=d;
			qwq.x=i;
			qwq.y=j;
			q.push(qwq);
		}
	}
	while(check()&&!q.empty())
	{
		node x=q.top();q.pop();
		if(find(x.x)!=find(x.y))sum+=x.val,fa[find(x.x)]=find(x.y),meerge++;
	}
	cout<<sum+(n-meerge)*v;
}
