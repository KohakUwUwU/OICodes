#include<bits/stdc++.h>
#define N 5005
#define M (int)2e5
using namespace std;
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
int n,m,vis[N],sum;
bool state;
int fa[N];
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
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>qwq.x>>qwq.y>>qwq.val,q.push(qwq);
	while(check()&&!q.empty())
	{
		node x=q.top();q.pop();
		if(find(x.x)!=find(x.y))sum+=x.val,fa[find(x.x)]=find(x.y);
	}
	if(!state)cout<<"orz";
	else cout<<sum;
}
