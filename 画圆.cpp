//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define db long double
using namespace std;

const int N=1e3+5;
db r,x[N],y[N];
int times;
inline db Convert(db angle)
{
	return angle*3.1415926535/180.0;
}
signed main()
{
	cout<<"������뾶:";
	cin>>r;
	cout<<"������Բ�ϵ����:";
	cin>>times;
	for(int i=0;i<times;i++)
	{
		x[i]=sin(Convert(360.0*i/times))*r;
		y[i]=cos(Convert(360.0*i/times))*r;
		cout<<fixed<<setprecision(6)<<x[i]<<' '<<y[i]<<'\n';
	}
	cout<<"Ҫ���Ͼ���Բ������������Ҫ������x y����,������Ҫ�����\n";
	db sx,sy;
	cin>>sx>>sy;
	for(int i=0;i<times;i++)
	{
		cout<<fixed<<setprecision(6)<<x[i]+sx<<' '<<y[i]+sy<<'\n';
	}
	int sb;
	cin>>sb;
	return 0;
}

