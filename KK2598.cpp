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

const int N=1e5+7;
int n,a[N],st[N],top,mx=0;
inline int Find(int t)//Ѱ�ҵ���t������a������
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
	cout<<"top:"<<top<<"  mx:"<<mx<<'\n';
}
signed main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int insert_p=Find(a[i]-1);
		int watch_p=Find(a[i]);
		if(watch_p!=0)mx=max(mx,i-st[watch_p]-1);
		else mx=max(mx,i-st[1]-1);
		top=insert_p+1;
		st[top]=i;
//		print_st();
//		cout<<"ip:"<<insert_p<<"  wp:"<<watch_p<<'\n';
	}
	cout<<mx;
	return 0;
}
