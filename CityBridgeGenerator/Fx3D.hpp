#pragma once
#include"xoy.hpp"
struct Dot3D
{
	int x,y,z;
};
struct Line3D
{
	double m,n,p;
	double x0,y0,z0;
	/*
	(m,n,p)是直线的空间向量 
	关于t：
	x=x0+mt;
	y=y0+nt;
	z=z0+pt;
	*/
	double XtoT(double x)
	{
		return (x-x0)/m;
	}
	double YtoT(double y)
	{
		return (y-y0)/n;
	}
	double ZtoT(double z)
	{
		return (z-z0)/p;
	}
	double TtoX(double t)
	{
		return x0+m*t;
	}
	double TtoY(double t)
	{
		return y0+n*t;
	}
	double TtoZ(double t)
	{
		return z0+p*t;
	}
};
struct Cube
{
	double x,y,z;
	double a,b,c;
	double spin;
	//x y z是离原点最近的那个顶点 
};
struct Sphere
{
	double x,y,z;
	double r;
};
struct Cylinder
{
	double x,y,z;//底面圆心 
	double r1,r2;//上底下底
	double spin; 
};
Line Line3Dto2D(Line3D l)
{
	Line ans;
	ans.k=l.m/l.n;
	ans.b=l.y0-l.x0*ans.k;
	return ans;
}
inline double Dis3D(Dot d1,Dot d2)
{
	return sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y)+(d1.z-d2.z)*(d1.z-d2.z));
}
inline double DotLine(Line3D l,Range r,Dot3D d)
{
	double tst=l.XtoT(r.st);
	double ted=l.XtoT(r.ed);
	Dot3D Center=d;
	Dot3D d1=(Dot3D){l.TtoX(tst),l.TtoY(tst),l.TtoZ(tst)};
	Dot3D d2=(Dot3D){l.TtoX(ted),l.TtoY(ted),l.TtoZ(ted)};
	double Center_d1=Dis3D(Center,d1);
	double d1_d2=Dis3D(d1,d2);
	double Center_d2=Dis3D(Center,d2);
	double p=(Center_d1+Center_d2+d1_d2)/2.0;
	double S=sqrt(p*(p-d1_d2)*(p-Center_d1)*(p-Center_d2));
	double H=2.0*S/d1_d2;
}
inline bool cmp(Dot x,Dot y)
{
	if(x.x!=y.x)return x.x>y.x;
	return x.y>y.y;
}
inline int LineCube(Line3D l,Range r,Cube c)
{
	double tst=l.XtoT(r.st);
	double ted=l.XtoT(r.ed);
	double yst=l.TtoY(tst);
	double yed=l.TtoY(ted);
	Dot d1=(Dot){c.x,c.y};
	Dot d2=(Dot){c.x+c.b*cos(DtoR(c.spin+90.0)),c.y+c.b*sin(DtoR(c.spin+90.0))};
	Dot d3=(Dot){c.x+c.a*cos(DtoR(c.spin)),c.y+c.a*sin(DtoR(c.spin))};
	Dot d4=(Dot){d2.x+d3.x-d1.x,d2.y+d3.y-d1.y};
	//顺时针1243
	Line l2d=Line3Dto2D(l);
	Line ll[5];
	ll[1]=GenerateLine(d1,d2);
	ll[2]=GenerateLine(d2,d4);
	ll[3]=GenerateLine(d4,d3);
	ll[4]=GenerateLine(d3,d1);
	if(ll[1]==l2d||ll[2]==l2d||ll[3]==l2d||ll[4]==l2d)return HOMO;
	Dot dd[5],timer;
	if(xxRange(ll[1],(Range){d1.x,d2.x},l2d,(Range){0,HOMO}))dd[++timer]=l2d.X(ll[1]);
	if(xxRange(ll[2],(Range){d2.x,d4.x},l2d,(Range){0,HOMO}))dd[++timer]=l2d.X(ll[2]);
	if(xxRange(ll[3],(Range){d4.x,d3.x},l2d,(Range){0,HOMO}))dd[++timer]=l2d.X(ll[3]);
	if(xxRange(ll[4],(Range){d3.x,d1.x},l2d,(Range){0,HOMO}))dd[++timer]=l2d.X(ll[4]);
	sort(dd+1,dd+1+timer,cmp);
	for(int i=2;i<=timer;i++)
	{
		if(abs(dd[i].x-dd[i-1].x)<=EPS&&abs(dd[i].y-dd[i-1].y)<=EPS)dd[i]=(Dot){0,0};
	}
	for(int i=1;i<=timer;i++)
	{
		if(!(r.st<=dd[i].x&&dd[i].x<=r.ed))dd[i]=(Dot){0,0};
	}
	sort(dd+1,dd+5,cmp);
	timer=1;
	while(dd[timer+1].x!=0||dd[timer+1].y!=0)timer++;
	if(timer==0)return 0;
	if(timer==1)
	{
		double zz=l.TtoZ(l.XtoT(dd[1].x));
		if(zz-c.z-c.c>EPS)return 0;
		return 1;
	}
	if(timer==2)
	{
		int cnt=0;
		for(int i=1;i<=2;i++)
		{
			double zz=l.TtoZ(l.XtoT(dd[i].x));
			if(zz-c.z-c.c<=EPS)cnt++;
		}
		return cnt;
	}
}
inline int LineSphere(Line3D l,Range r,Sphere s)
{
	double tst=l.XtoT(r.st);
	double ted=l.XtoT(r.ed);
	Dot3D Center=(Dot3D){s.x,s.y,s.z};
	Dot3D d1=(Dot3D){l.TtoX(tst),l.TtoY(tst),l.TtoZ(tst)};
	Dot3D d2=(Dot3D){l.TtoX(ted),l.TtoY(ted),l.TtoZ(ted)};
	double Center_d1=Dis3D(Center,d1);
	double d1_d2=Dis3D(d1,d2);
	double Center_d2=Dis3D(Center,d2);
	double p=(Center_d1+Center_d2+d1_d2)/2.0;
	double S=sqrt(p*(p-d1_d2)*(p-Center_d1)*(p-Center_d2));
	double H=2.0*S/d1_d2;
	double distance=0;
	if(H<Center_d1&&H<Center_d2)distance=min(Center_d1,Center_d2);
	else distance=H;
	if(abs(distance-s.r)<=EPS)return 1;
	if(distance<s.r)return 2;
	return 0;
}
inline int LineCylinder(Line3D l,Range r,Cylinder c)
{
	
}
