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

int n,m,nD,d[20],f[20][2][2],ok[20][2][2];
inline void pre(int k)
{
	nD=0;
	while(k)
	{
		d[++nD]=k%10;
		k/=10;
	}
}
inline int F(int p,int lmt,int pre1)
{
	if(p==0)return 1;
	if(ok[p][lmt][pre1])return f[p][lmt][pre1];
	ok[p][lmt][pre1]=1;
	for(int i=0;i<=(lmt?d[p]:9);i++)
	{
		if(i==4)continue;
		if(i==3&&pre1)continue;
		f[p][lmt][pre1]+=F(p-1,lmt&&i==d[p],i==1);
	}
	return f[p][lmt][pre1];
}
inline int work(int k)
{
	memset(f,0,sizeof(f));
	memset(ok,0,sizeof(ok));
	pre(k);
	return F(nD,1,0);
}
signed main()
{
	freopen("thirteen.in","r",stdin);
	freopen("thirteen.out","w",stdout);
	n=read(),m=read();
	cout<<work(m)-work(n-1);
	return 0;
}

