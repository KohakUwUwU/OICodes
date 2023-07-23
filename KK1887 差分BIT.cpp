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

#define N (int)1e5+5
#define mod 100000007
vector<int>G[N];
int n,m,timer,cf[N*2],tI[N],tO[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_son(int u,int fa)
{
	tI[u]=++timer;
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=fa)dfs_son(G[u][i],u);
	tO[u]=timer;
}
inline int lowbit(int x)
{
	return x&-x;
}
inline void addoperation(int pos,int u)
{
	while(pos<=n)cf[pos]+=u,pos+=lowbit(pos);
}
inline void add(int pos,int u)
{
	addoperation(tI[pos],u),addoperation(tO[pos]+1,-u);
}
inline int getsum(int pos)
{
	int ans=0;
	while(pos>=1)ans+=cf[pos],pos-=lowbit(pos);
	return ans; 
}
signed main()
{
	freopen("company.in","r",stdin);
	freopen("company.out","w",stdout);
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v);
	dfs_son(1,0);
	for(int i=1;i<=m;i++)
	{
		int x=read(),w=read();
		add(x,w);
		cout<<getsum(x)<<endl;
	}
	return 0;
}

