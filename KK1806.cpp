#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch ��������ʱ
    if (ch == '-') w = -1;        // �ж��Ƿ�Ϊ��
    ch = getchar();               // ��������
  }
  while (ch >= '0' && ch <= '9') {  // ch ������ʱ
    x = x * 10 + (ch - '0');  // ���¶�������֡��ӡ��� x �ĺ���
    // x �� int ���ͣ�char ���͵� ch �� ��0�� �ᱻ�Զ�תΪ���Ӧ��
    // ASCII �룬�൱�ڽ� ch ת��Ϊ��Ӧ����
    // �˴�Ҳ����ʹ�� (x<<3)+(x<<1) ��д�������� x*10
    ch = getchar();  // ��������
  }
  return x * w;  // ���� * ������ = ʵ����ֵ
}

const int N=2e5+5;
int n,ans,fa[N],sz[N];
vector<pair<int,int> >p;
vector<int>G[N];
inline int Find(int x)
{
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline void Merge(int x,int y)
{
	fa[Find(x)]=Find(y);
}
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
//	cout<<u<<'\n';
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
signed main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c==1)p.push_back(make_pair(a,b));
		else Merge(a,b),addEdge(a,b);
	}
//	for(int i=1;i<=n;i++)cout<<G[i].size()<<' ';
//	cout<<'\n';
	for(int i=1;i<=n;i++)if(fa[i]==i)dfs(i,0),ans+=sz[i]*(sz[i]-1)/2;
//	for(int i=1;i<=n;i++)cout<<sz[i]<<' ';
//	cout<<endl;
	int max_delta=0;
	for(int i=0;i<p.size();i++)
	{
		int u=p[i].first,v=p[i].second;
		u=Find(u),v=Find(v);
		int sz1=sz[u],sz2=sz[v];
		max_delta=max((sz1+sz2)*(sz1+sz2-1)/2-sz1*(sz1-1)/2-sz2*(sz2-1)/2,max_delta);
	}
	cout<<n*(n-1)/2-(ans+max_delta);
	return 0;
}
