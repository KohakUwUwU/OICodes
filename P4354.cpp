#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int m,n,sum;
double x1,xd1,x2,y2,k,b,ansa,ansb,ansc,ansx1,ansx2,delta;
struct dot
{
	double x,y;
	double r;
};
map<int,dot>dt;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%lf%lf%lf",&dt[i].x,&dt[i].y,&dt[i].r);
	scanf("%d",&n);
	for(int i=1;i<=n;i++,sum=0)
	{
		scanf("%lf%lf%lf%lf",&x1,&xd1,&x2,&y2);
		k=(xd1-y2)/(x1-x2);
		b=xd1-k*x1;
		ansa=k*k+1;
		for(int j=1;j<=m;j++)
		{
			ansb=-2*dt[j].x+2*k*b-2*k*dt[j].y;
			ansc=dt[j].x*dt[j].x+dt[j].y*dt[j].y+b*b-2*b*dt[i].y-dt[i].r*dt[i].r;
			delta=ansb*ansb-4*ansa*ansc;
			ansx1=(-ansb+sqrt(delta))/(2*ansa);
			ansx2=(-ansb-sqrt(delta))/(2*ansa);
			if(delta>=0&&((ansx1>min(x1,x2)&&ansx1<max(x1,x2))||(ansx2>min(x1,x2)&&ansx2<max(x1,x2))))sum++;
		}
		printf("%d\n",sum);
	}
}
