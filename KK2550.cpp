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

int n,nD,d[20],f[20][2],ok[20][2];
inline void pre()
{
	while(n)
	{
		d[++nD]=n%10;
		n/=10;
	}
}
inline int F(int p,int lmt)
{
	if(p==0)return 1;
	if(ok[p][lmt])return f[p][lmt];
	ok[p][lmt]=1,f[p][lmt]=0;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(i==4)continue;
		f[p][lmt]+=F(p-1,lmt&&i==d[p]);
	}
	return f[p][lmt];
}
signed main()
{
	freopen("four.in","r",stdin);
	freopen("four.out","w",stdout);
	n=read();
	pre();
	cout<<F(nD,1)-1;
	return 0;
}

