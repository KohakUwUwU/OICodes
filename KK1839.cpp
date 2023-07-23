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
	int id,clr;
};
const int N=2e5+5;
int n,m,timer;
int p[N][30],sz[N],son[N],d[N],tI[N],tO[N],dfn[N],cnt[N],ans[N];
vector<int>G[N];
vector<query>q[N];
set<int>S[N*2];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline int LA(int u,int level)
{
	int i=21;
	while(level)
	{
		if(level>=(1<<i))u=p[u][i],level-=1<<i;
		i--;
	}
	return u;
}
inline void dfs_sz_son(int u)
{
	dfn[++timer]=u,tI[u]=timer;
	sz[u]=1,son[u]=0,d[u]=d[p[u][0]]+1;
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
	if(tag)cnt[d[u]]++;
	else cnt[d[u]]--;
}
inline void aTree(int u,int tag)
{
	for(int i=tI[u];i<=tO[u];i++)
	{
		aNode(dfn[i],tag);
	}
}
inline void dfs_work(int u,bool hvy)
{
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])dfs_work(G[u][i],0);
	if(son[u])dfs_work(son[u],1);
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=son[u])aTree(G[u][i],1);
	aNode(u,1);
	for(int i=0;i<q[u].size();i++)ans[q[u][i].id]=cnt[d[u]+q[u][i].clr]-1;
	if(!hvy)aTree(u,0);
}
signed main()
{
	freopen("bro.in","r",stdin);
	freopen("bro.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)p[i][0]=read(),addEdge(p[i][0],i);
	for(int i=1;i<=21;i++)for(int j=1;j<=n;j++)p[j][i]=p[p[j][i-1]][i-1];
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),k=read();
		q[LA(u,k)].push_back((query){i,k});
	}
	for(int i=1;i<=n;i++)if(!p[i][0])dfs_sz_son(i);
	for(int i=1;i<=n;i++)if(!p[i][0])dfs_work(i,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

