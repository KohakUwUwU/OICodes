#include<bits/stdc++.h>
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

#define N (int)1e5+5
vector<int>G[N];
int n,m,sz[N],son[N],top[N],d[N],father[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	sz[u]=1,son[u]=0,d[u]=d[fa]+1,father[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]||sz[v]==sz[son[u]]&&v<son[u])son[u]=v;
	}
}
inline void dfs_top(int u,int fa)
{
	if(u==son[fa])top[u]=top[fa];
	else top[u]=u;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_top(v,u);
	}
}
inline int query(int u,int v)
{
	int cnt=1;
	while(top[u]!=top[v])
	{
		if(d[top[u]]<d[top[v]])v=father[top[v]];
		else u=father[top[u]];
		++cnt;
	}
	return cnt;
}
int main()
{
	freopen("pathdecomposition.in","r",stdin);
	freopen("pathdecomposition.out","w",stdout);
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	dfs_top(1,0);
	m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),cout<<query(u,v)<<' ';
	return 0;
}

