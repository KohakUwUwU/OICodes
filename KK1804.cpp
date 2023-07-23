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

const int N=1e5+5;
int n,p[N];
double num[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline void dfs(int u,int fa)
{
	num[u]+=num[fa];
	for(int i=0;i<G[u].size();i++)dfs(G[u][i],u);
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	num[1]=1;
	for(int i=2;i<=n;++i)p[i]=read(),num[i]=1,addEdge(p[i],i);
	dfs(1,0);
	double ans=0.0;
	for(int i=1;i<=n;i++)ans+=1.0/double(num[i]);
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}

