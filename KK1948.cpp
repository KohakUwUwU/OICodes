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

const int N=2e5+7;
int n,a[N],p[N],nxt[N],pre[N],ans[N];
signed main()
{
	freopen("heroes.in","r",stdin);
	freopen("heroes.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),p[a[i]]=i;
	for(int i=1;i<=n;i++)nxt[i]=i+1,pre[i]=i-1;
	for(int i=1;i<=n;i++)
	{
		ans[p[i]]=nxt[p[i]];
		nxt[pre[p[i]]]=nxt[p[i]];
		pre[nxt[p[i]]]=pre[p[i]];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
