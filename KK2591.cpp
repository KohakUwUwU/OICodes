#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
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
int n,m,ans,head=0,nxt[N];
struct point
{
	int x,y;
}q1[N],q2[N];
#define f(x,y) for(int i=x;i<=y;i++)
inline bool cmp(const point&x,const point&y)
{
	return x.x<y.x||x.x==y.x&&x.y<y.y;
}
signed main()
{
//	freopen("iron.in","r",stdin);
//	freopen("iron.out","w",stdout);
	n=read(),m=read();
	f(1,n)q1[i].x=read();
	f(1,n)q1[i].y=read();
	f(1,m)q2[i].x=read();
	f(1,m)q2[i].y=read();
	sort(q1+1,q1+1+n,cmp);sort(q2+1,q2+1+m,cmp);
	nxt[m]=N-1;
	int ff=m;
	for(int i=m-1;i>=1;i--)
	{
		if(q2[i].x==q2[i+1].x)nxt[i]=nxt[i+1];
		else nxt[i]=ff,ff=i;
	}
	for(int i=1;i<=n;i++)
	{
		int j=17;
		while(q2[head].x<q1[i].x&&j>=0&&head<=m)
		{
			if(head+(1<<j)<=m&&q2[head+(1<<j)].x<q1[i].x)head+=(1<<j);
			j--;
		}
		if(head+1<=m&&q2[head].x<q1[i].x)head++;
//		while(q2[head].x<q1[i].x&&head<=m)head++;
		for(int j=head;j<=m&&q2[j].x<=q1[i].y;j=nxt[j])
		{
			if(q2[j].y<q1[i].y)continue;
			ans=max(ans,q1[i].y-q2[j].x+1);
		}
	}
	cout<<ans;
	return 0;
}
