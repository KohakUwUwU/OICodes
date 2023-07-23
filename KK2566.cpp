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

const int N=2001;
const int mod=998244353;
int n,a[N],b[N],yh[N][N];
inline void work(int k)
{
	b[k]=a[k];
	int neg=1;
	for(int i=k;i>=0;i--,((n-k)%2==1)&&(neg=-neg))
	{
		a[i]-=yh[k][i]*neg*b[k]%mod;
		a[i]=(a[i]%mod+mod)%mod;
//		for(int j=0;j<=n;j++)cout<<a[j]<<' ';
//		cout<<'\n';
	}
}
signed main()
{
	n=read();
	for(int i=0;i<=n;i++)cin>>a[i];
	yh[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		yh[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			yh[i][j]%=mod;
		}
	}
	for(int i=n;i>=0;i--)
	{
		work(i);
	}
	for(int i=0;i<=n;i++)
	{
		b[i]%=mod;
		while(b[i]>=mod)b[i]-=mod;
		while(b[i]<0)b[i]+=mod;
		cout<<b[i]<<' ';
	}
	return 0;
}
