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

const int N=1e5+7,INF=1145141919810;
int n,a[N],f[N],st[N],top;
inline int Find(int t)
{
	int p=0;
	for(int i=20;i>=0;i--)if(p+(1<<i)<=top&&a[st[p+(1<<i)]]>t)p+=(1<<i);
	return p;
}
inline void print_st()
{
	cout<<"st:  ";
	for(int i=1;i<=top;i++)cout<<st[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	cout<<'\n';
//	cout<<"top:"<<top<<"  cnt:"<<cnt<<'\n';
}
signed main()
{
	freopen("jumps.in","r",stdin);
	freopen("jumps.out","w",stdout);
	n=read();
	f[0]=INF,f[1]=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read(),f[i+1]=INF;
		int wP=Find(a[i]-1);
		for(int j=wP;j<=top;j++)f[i]=min(f[st[j]]+1,f[i]);
		if(a[st[wP]]==a[i])st[top=wP]=i;
		else st[top=wP+1]=i;
//		print_st();
	}
	cout<<f[n];
	return 0;
}

