#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std; 
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;   c=getchar();}
    while(c>='0'&&c<='9'){x=(x+(x<<2)<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}
int n,m,ttime=0,tot=0;
//ttime��¼��ʱ��,tot��¼��
int ans1,ans2,cnt1=1,cnt2=1,t1,t2;
//ans��ʾ���˵�·�̣�cnt��ʾ��ǰ�Ľ׶�,t��ʾ״̬ת�Ƶ�ʱ���
struct node{
	int v,t;
}n1[1005],m1[1005];
bool judge(int x,int y)
{
	if(x>y) return 1;
	else return 0;
}
bool flag;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)n1[i].v=read(),n1[i].t=read(),ttime+=n1[i].t;
	for(int i=1;i<=m;++i) m1[i].v=read(),m1[i].t=read();
	if(n1[1].v>m1[1].v) flag=1;
	else flag=0;
	t1=n1[1].t,t2=m1[1].t;//��ʼ��
	for(int i=1;i<=ttime;++i)//ö��ÿһ���״̬
	{
		ans1+=n1[cnt1].v;
		ans2+=m1[cnt2].v;//ͨ������·��
		if(judge(ans1,ans2)!=flag) tot++,flag=!flag;
        //��������Ⱥ����仯����¼�µ�ǰ״̬�����´�
		if(i==t1) cnt1++,t1+=n1[cnt1].t;
		if(i==t2) cnt2++,t2+=m1[cnt2].t;
        //���Խ�����һ״̬
	}
	cout<<tot<<endl;
}
