//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e4+5;
int n,m,b[N],p[N];
struct Node
{
	int id,gap,dst;
};
queue<Node>q;
bitset<N>vst[N];
vector<int>g[N];
inline void go(int id,int gap,int dst)
{
	if(id<1||id>n)return ;
	if(vst[id][gap])return ;
	q.push((Node){id,gap,dst+1});
	vst[id][gap]=true;
}
inline int bfs()
{
	q.push((Node){b[1],p[1],0});
	vst[b[1]][p[1]]=1;
	while(!q.empty())
	{
		int id=q.front().id;
		int gap=q.front().gap;
		int dst=q.front().dst;
		if(id==b[2])return dst;
		q.pop();
		go(id-gap,gap,dst);
		go(id+gap,gap,dst);
		for(int i=0;i<g[id].size();i++)
		{
			int gap=g[id][i];
			go(id-gap,gap,dst);
			go(id+gap,gap,dst);
		}
	}
	return -1;
}
signed main()
{
	freopen("apology.in","r",stdin);
	freopen("apology.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i]>>p[i];
		g[b[i]].push_back(p[i]);
	}
	cout<<bfs();
	return 0;
}

