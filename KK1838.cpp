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

struct query
{
	int id,d;
};
const int N=1e5+5;
int n,m,namecnt,timer;
int p[N],clr[N],sz[N],son[N],d[N],tI[N],tO[N],dfn[N],ans[N];
vector<int>G[N];
vector<query>q[N];
map<string,int>id;//��string��id��¼���� 
set<int>S[N*2];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline void dfs_sz_son(int u)
{
	dfn[++timer]=u,tI[u]=timer;
	sz[u]=1,son[u]=0,d[u]=d[p[u]]+1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs_sz_son(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
	tO[u]=timer;
}
inline void aNode(int u,bool tag)
{
	if(tag)S[d[u]].insert(clr[u]);
	else S[d[u]].erase(clr[u]);
}
inline void aTree(int u,int tag)
{
	for(int i=tI[u];i<=tO[u];i++)aNode(dfn[i],tag);
}
inline void dfs_work(int u,int hvy)
{
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])dfs_work(G[u][i],0);
	if(son[u])dfs_work(son[u],1);
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])aTree(G[u][i],1);
	aNode(u,1);
	for(int i=0;i<q[u].size();i++)ans[q[u][i].id]=S[d[u]+q[u][i].d].size();
	if(!hvy)aTree(u,0);
}
signed main()
{
	freopen("offspring.in","r",stdin);
	freopen("offspring.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		if(!id[str])id[str]=++namecnt;
		clr[i]=id[str];
		p[i]=read();
		if(p[i])addEdge(p[i],i);
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),k=read();
		q[u].push_back((query){i,k});
	}
	for(int i=1;i<=n;i++)if(!p[i])dfs_sz_son(i);
	for(int i=1;i<=n;i++)if(!p[i])dfs_work(i,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

