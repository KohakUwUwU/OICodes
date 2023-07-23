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
int m,n,a[N],ans[N];
struct point
{
	int x,y;
}p[N],s[N];
struct query
{
	int u,v,rk;
}q[N];
#define f(x,y) for(int i=x;i<=y;i++)
inline bool P(point x,point y)
{
	return x.x>y.x||x.x==y.x&&x.y<y.y;
}
inline bool Q(query x,query y)
{
	return x.u>y.u||x.u==y.u&&x.v<y.v;
}
signed main()
{
	freopen("corner.in","r",stdin);
	freopen("corner.out","w",stdout);
	n=read(),m=read();
	f(1,n)p[i].x=read();
	f(1,n)p[i].y=read();
	f(1,m)q[i].u=read();
	f(1,m)q[i].v=read();
	f(1,m)q[i].rk=i;
	sort(p+1,p+1+n,P);sort(q+1,q+1+m,Q);
	int cnt=0,j=1;
	for(int i=1;i<=m;i++)
	{
		while(j<=n&&p[j].x>q[i].u){while(cnt&&p[j].y>=s[cnt].y)cnt--;s[++cnt]=p[j++];}
		int l=1,r=cnt,res=1145141145;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(s[mid].y>q[i].v)res=s[mid].x,l=mid+1;
			else r=mid-1;
			ans[q[i].rk]=(res==1145141145?0:res);
		}
	}
	f(1,m)cout<<ans[i]<<' ';
	return 0;
}

