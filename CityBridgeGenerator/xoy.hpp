#pragma once
#include<bits/stdc++.h>
#include"variety.hpp"
using namespace std;
struct Dot
{
	double x,y;
};
struct DoubleDot
{
	Dot dot1,dot2;
};
struct Range
{
	double st,ed;	
};
struct Line
{
	double k,b;
	double f(double x)
	{
		return k*x+b;
	}
	Dot X(Line l)
	{
		if(k==l.k)
		{
			cout<<"FATAL ERROR: TWO LINES WHICH ARE PARALLEL!!!\n";
			return (Dot){HOMO,HOMO};
		}
		return (Dot){(l.b-b)/(k-l.k),k*(l.b-b)/(k-l.k)+b}; 
	}
	const operator ==(Line a)const
	{
		return a.k==k&&a.b==b;
	};
};
Line GenerateLine(Dot d1,Dot d2)
{
	int k=(d2.y-d1.y)/(d2.x-d1.x);
	int b=d1.y-d1.x*k;
	return (Line){k,b};
}
struct Circle
{
	double x0,y0,r,d,e,f;
	Circle(double dd,double ee,double ff,double s00)
	{
		d=dd;e=ee;f=ff;
		if(f-d*d/4.0-e*e/4.0>EPS/1.0)
		{
			cout<<"FATAL ERROR: A CIRCLE IS INVALID!!!\n";
		}
		x0=-d/2.0;y0=-e/2.0;r=d*d/4.0+e*e/4.0-f;
	}
	Circle(double x00,double y00,double rr)
	{
		x0=x00;y0=y00;r=rr;
		d=-2.0*x0;
		e=-2.0*y0;
		f=x0*x0+y0*y0-r*r;
	}
	int ol(Line l)//返回个数 
	{
		double k=l.k,b=l.b;
		double delta=(2*k*b+d+e*k)*(2*k*b+d+e*k)-4*(k*k+1)*(b*b+e*b+f);
		if(abs(delta)<=EPS)return 1;
		if(delta>0)return 2;
		return 0;
	}
	DoubleDot oldot(Line l)//返回两个解
	{
		double k=l.k,b=l.b;
		double delta=(2*k*b+d+e*k)*(2*k*b+d+e*k)-4*(k*k+1)*(b*b+e*b+f);
		if(abs(delta)<=EPS)
		{
			double xx=-(2*k*b+d+e*k)/(2.0*(k*k+1));
			double yy=k*xx+b;
			return (DoubleDot){(Dot){xx,yy},(Dot){HOMO,HOMO}};
		}
		if(delta>0)
		{
			double xx1=(-(2*k*b+d+e*k)+sqrt(delta))/(2.0*(k*k+1));
			double xx2=(-(2*k*b+d+e*k)-sqrt(delta))/(2.0*(k*k+1));
			double yy1=k*xx1+b;
			double yy2=k*xx2+b;
			return (DoubleDot){(Dot){xx1,yy1},(Dot){xx2,yy2}};
		}
	}
	int oo(Circle o)//返回个数 
	{
		double r1=r,r2=o.r;
		Dot d1=(Dot){x0,y0};
		Dot d2=(Dot){o.x0,o.y0};
		double dis=sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
		if(abs(dis-r1-r2)<=EPS)return 1;
		if(dis>r1+r2)return 0;
		return 2;
	}
};
inline bool Rangelegal(Range a)
{
	return a.st<=a.ed;
}
inline RangeI(Range a,Range b)//交集 
{
	if(!Rangelegal(a)||!Rangelegal(b))return EmptyRange;
	if(a.x>b.y||a.y<b.x)return EmptyRange;
	return (Range){max(a.x,b.x),min(a.y,b.y)};
}
inline int xxRange(Line a,Range ar,Line b,Range br)
{
	if(a==b)return HOMO;
	if(a.k==b.k)return 0;
	Dot d=a.X(b);
	if(ar.st<=d.x&&d.x<=ar.ed&&br.st<=d.x&&d.x<=br.ed)return 1;
	else return 0;
}
inline int xoRange(Line a,Range ar,Circle o)
{
	int cnt=0;
	DoubleDot _2d=o.oldot(a);
	Dot dot1=_2d.dot1,dot2=_2d.dot2;
	if(ar.st<=dot1.x&&dot1.x<=ar.ed)cnt++;
	if(ar.st<=dot2.x&&dot2.x<=ar.ed)cnt++;
	return cnt;
}
