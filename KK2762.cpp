//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const signed N=1e5+7,P=605;
signed n,m,L,x[N];
vector<signed>a[P][P];//ģ��  ���� 
vector<signed>val[10009];
inline int read() {
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
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 �� '0'
}
signed main()
{
	freopen("modularity.in","r",stdin);
	freopen("modularity.out","w",stdout);
	n=read(),m=read();
	L=min((signed)(sqrt(m*10009/n)+1),600);
	for(register signed i=1;i<=n;++i)x[i]=read(),val[x[i]].push_back(i);
	for(register signed i=1;i<=L;++i)//p
	{
		for(register signed j=1;j<=n;++j)//����ö�� 
		{
			a[i][x[j]%i].push_back(j);
		}
	}
	for(register signed i=1;i<=m;++i)
	{
		signed l=read(),r=read(),p=read(),v=read();
		if(p<=L)
		{
			signed lb=lower_bound(a[p][v].begin(),a[p][v].end(),l)-a[p][v].begin();
			signed rb=upper_bound(a[p][v].begin(),a[p][v].end(),r)-a[p][v].begin();
			write(rb-lb);
			printf(" ");
		}
		else
		{
			int ans=0;
			for(register signed i=v;i<=10000;i+=p)
			{
				signed lb=lower_bound(val[i].begin(),val[i].end(),l)-val[i].begin();
				signed rb=upper_bound(val[i].begin(),val[i].end(),r)-val[i].begin();
				ans+=rb-lb;
			}
			write(ans);
			printf(" ");
		}
	}
	return 0;
}
