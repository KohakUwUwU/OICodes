#include<bits/stdc++.h>
using namespace std;
int n,v;//������ʾ 
int m[31],h[31];//����ÿ����������� 
int minn=1000000001;//�������մ� 
inline void baosou(int num,int xm,int xh)//�����ֱ�Ϊ �¼����±� ��ʱС�������ܶ� С������ܶ� 
{
	if(num==n+1)
	{
		if(xm+xh>=v)minn=abs(xm-xh)<minn?abs(xm-xh):minn;
		//���ﲻ��ԭ��min��Ϊ���Ż�������֪����û������ qwq�� 
		return ;
	}
	//�úڰ壡���� 
	baosou(num+1,xm,xh);//����²��� 
	baosou(num+1,xm+m[num],xh+h[num]);//��������� 
}
int main()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++)cin>>m[i]>>h[i];
	baosou(1,0,0);
	if(minn==1000000001)cout<<-1;
	else cout<<minn;
}
