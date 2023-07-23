#include<bits/stdc++.h>
using namespace std;
int n,v;//如题所示 
int m[31],h[31];//储存每次输入的数据 
int minn=1000000001;//储存最终答案 
inline void baosou(int num,int xm,int xh)//参数分别为 事件的下标 此时小明的亲密度 小红的亲密度 
{
	if(num==n+1)
	{
		if(xm+xh>=v)minn=abs(xm-xh)<minn?abs(xm-xh):minn;
		//这里不用原版min是为了优化（？不知道有没有作用 qwq） 
		return ;
	}
	//敲黑板！！！ 
	baosou(num+1,xm,xh);//这件事不做 
	baosou(num+1,xm+m[num],xh+h[num]);//这件事做！ 
}
int main()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++)cin>>m[i]>>h[i];
	baosou(1,0,0);
	if(minn==1000000001)cout<<-1;
	else cout<<minn;
}
