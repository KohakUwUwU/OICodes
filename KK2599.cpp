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

const int N=5e5+7;
int n,a[N],st[N],top,cnt;
inline int Find(int t)
{
	int p=0;
	for(int i=20;i>=0;i--)
	{
		if(p+(1<<i)>top||a[st[p+(1<<i)]]<=t)continue;
		p+=(1<<i);
	}
	return p;
}
inline void print_st()
{
	cout<<"st:  ";
	for(int i=1;i<=top;i++)cout<<st[i]<<' ';
	cout<<'\n';
	cout<<"top:"<<top<<"  cnt:"<<cnt<<'\n';
}
signed main()
{
	freopen("u.in","r",stdin);
	freopen("u.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int wP=Find(a[i]),iP=Find(a[i]-1);
		cnt+=top-wP;
		if(wP)cnt++;
		st[top=iP+1]=i;
//		print_st();
	}
	cout<<cnt;
	return 0;
}

