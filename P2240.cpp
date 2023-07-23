#include<iostream>
#include<queue>
#include<iomanip>
#define R register
using namespace std;
int n,t;
struct node
{
	double m,v;
};
//inline bool cmp(node x,node y)
//{
//	return x.v/x.m>y.v/y.m;
//}
struct cmp
{
	bool operator()(node x,node y)
	{
		return x.v/x.m>y.v/y.m;
	}
};
priority_queue<node,vector<node>,cmp >G;
int main()
{
	scanf("%d%d",&n,&t);
	for(R int i=1;i<=n;i++)
	{
		R node x;
		scanf("%lf%lf",&x.m,&x.v);
		G.push(x);
	}
	R double space=0,value=0;
	while(!G.empty())
	{
		node k=G.top();
		G.pop();
		if(space+k.m>t)
		{
			value+=k.v*((t-k.m)/k.m);
			cout<<fixed<<setprecision(2)<<value;
			return 0;
		}
		else
		{
			value+=k.v;
		}
	}
	cout<<fixed<<setprecision(2)<<value;
}
