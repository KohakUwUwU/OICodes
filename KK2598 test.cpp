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

int a[50]={0,1,2,5,7,8,10,13};
inline int mtc(int t)//Ѱ�ҵ�����t�ĵ���ջ������ 
{
	int p=0;
	for(int i=20;i;--i)
	{
		if(p+(1<<i)>=100||a[p+(1<<i)]<=t)continue;
		p+=(1<<i);
	}
	return p;
} 
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		tmp=read();
		cout<<mtc(tmp)<<' ';
	}
	return 0;
}

