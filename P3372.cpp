#include<bits/stdc++.h>
typedef long long ll;
#define int ll
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
struct node
{
	int l,r,val,add;
}t[N*4];
int a[N],n,m;
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].val=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline void spread(int p)
{
	if(t[p].add)
	{
		t[p*2].val+=t[p].add*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].val+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
		t[p*2].add+=t[p].add,t[p*2+1].add+=t[p].add;
		t[p].add=0;
	}
}
inline void change(int p,int x,int y,int k)
{
	if(x<=t[p].l&&t[p].r<=y)
	{
		t[p].val+=k*(t[p].r-t[p].l+1);
		t[p].add+=k;
		return ;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(x<=mid)change(p*2,x,y,k);
	if(y>mid)change(p*2+1,x,y,k);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline int ask(int p,int x,int y)
{
	if(x<=t[p].l&&t[p].r<=y)return t[p].val;
	spread(p);
	int ans=0,mid=t[p].l+t[p].r>>1;
	if(x<=mid)ans+=ask(p*2,x,y);
	if(y>mid)ans+=ask(p*2+1,x,y);
	return ans;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,opt,x,y,k;i<=m;i++)
	{
		opt=read();
		if(opt==1)x=read(),y=read(),k=read(),change(1,x,y,k);
		if(opt==2)x=read(),y=read(),printf("%ld\n",ask(1,x,y));
	}
	return 0;
}

