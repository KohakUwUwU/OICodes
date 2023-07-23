#pragma once
#include<bits/stdc++.h>
#include"StdConstDefine.h"
using namespace std;
struct Dot
{
	double x, y;
};
struct DoubleDot
{
	Dot dot1, dot2;
};
struct Ranging
{
	double st, ed;
};
Ranging EmptyRanging = { 114514,-114514 };
struct Line
{
	double k, b;
	double f(double x)
	{
		return k * x + b;
	}
	Dot X(Line l)
	{
		if (k == l.k)
		{
			cout << "FATAL ERROR: TWO LINES WHICH ARE PARALLEL!!!\n";
			return { HOMO, HOMO };
		}
		return { (l.b - b) / (k - l.k), k* (l.b - b) / (k - l.k) + b };
	}
	const bool operator ==(Line a)const
	{
		return a.k == k && a.b == b;
	};
};
struct Circle
{
	double x0, y0, r, d, e, f;
	Circle(double dd, double ee, double ff, double s00)
	{
		d = dd; e = ee; f = ff;
		if (f - d * d / 4.0 - e * e / 4.0 > EPS / 1.0)
		{
			cout << "FATAL ERROR: A CIRCLE IS INVALID!!!\n";
		}
		x0 = -d / 2.0; y0 = -e / 2.0; r = d * d / 4.0 + e * e / 4.0 - f;
	}
	Circle(double x00, double y00, double rr)
	{
		x0 = x00; y0 = y00; r = rr;
		d = -2.0 * x0;
		e = -2.0 * y0;
		f = x0 * x0 + y0 * y0 - r * r;
	}
	int ol(Line l)//���ظ��� 
	{
		double k = l.k, b = l.b;
		double delta = (2 * k * b + d + e * k) * (2 * k * b + d + e * k) - 4 * (k * k + 1) * (b * b + e * b + f);
		if (abs(delta) <= EPS)return 1;
		if (delta > 0)return 2;
		return 0;
	}
	DoubleDot oldot(Line l)//����������
	{
		double k = l.k, b = l.b;
		double delta = (2 * k * b + d + e * k) * (2 * k * b + d + e * k) - 4 * (k * k + 1) * (b * b + e * b + f);
		if (abs(delta) <= EPS)
		{
			double xx = -(2 * k * b + d + e * k) / (2.0 * (k * k + 1));
			double yy = k * xx + b;
			return { { xx, yy }, { HOMO, HOMO } };
		}
		if (delta > 0)
		{
			double xx1 = (-(2 * k * b + d + e * k) + sqrt(delta)) / (2.0 * (k * k + 1));
			double xx2 = (-(2 * k * b + d + e * k) - sqrt(delta)) / (2.0 * (k * k + 1));
			double yy1 = k * xx1 + b;
			double yy2 = k * xx2 + b;
			return { { xx1, yy1 }, { xx2, yy2 } };
		}
	}
	int oo(Circle o)//���ظ��� 
	{
		double r1 = r, r2 = o.r;
		Dot d1 = { x0,y0 };
		Dot d2 = { o.x0,o.y0 };
		double dis = sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
		if (abs(dis - r1 - r2) <= EPS)return 1;
		if (dis > r1 + r2)return 0;
		return 2;
	}
};
struct Dot3D
{
	double x, y, z;
};
struct Line3D
{
	double m, n, p;
	double x0, y0, z0;
	/*
	(m,n,p)��ֱ�ߵĿռ�����
	����t��
	x=x0+mt;
	y=y0+nt;
	z=z0+pt;
	*/
	double XtoT(double x)
	{
		return (x - x0) / m;
	}
	double YtoT(double y)
	{
		return (y - y0) / n;
	}
	double ZtoT(double z)
	{
		return (z - z0) / p;
	}
	double TtoX(double t)
	{
		return x0 + m * t;
	}
	double TtoY(double t)
	{
		return y0 + n * t;
	}
	double TtoZ(double t)
	{
		return z0 + p * t;
	}
};
struct Cube
{
	double x, y, z;
	double a, b, c;
	double spin;
	//x y z����ԭ��������Ǹ����� 
};
struct Sphere
{
	double x, y, z;
	double r;
};
struct Cylinder
{
	double x, y, z;//����Բ�� 
	double r1, r2;//�ϵ��µ�
	double spin;
};
struct Element
{
	//ע��Ĭ����cube center=false sphere��ԭ�� 
	//ע���ݲ�֧�ֶ���κͶ�����
	//ע��֧�ֵ����η��������ʾ��û�������꣬���½�
	//ע��2Dģ��Ŀǰ���� 
	//ע��ֻ�ܰ�������ڵ�һ����
	//ע��һ�齨����������һ��
	int type;//Ԫ������ 
	double cdd[8];//Ԫ�ز���candidate
	double scale[4];//Ŀǰ���� 
	double resize[4]; bool rsauto;//Ŀǰ���� 
	double rotate[5];//Ŀǰ����cube x,y����ת��sphere��ת��cylinder x,y��ת
	double translate[4];
	double mirror[4];//Ŀǰ���� 
	double color[5];//���Ƽ�ʹ�� 
	int to;//Ŀ��Ԫ�� 
	int opt;//��Ŀ��Ԫ�صĲ���������ǰԪ����ǰ 
	Element()
	{
		type = 0;
		memset(cdd, 0, sizeof(cdd));
		memset(scale, 0, sizeof(scale));
		memset(resize, 0, sizeof(resize)); rsauto = false;
		memset(rotate, 0, sizeof(rotate));
		memset(translate, 0, sizeof(translate));
		memset(mirror, 0, sizeof(mirror));
		memset(color, 0, sizeof(color));
		to = 0;
		opt = 0;
	}
	void ElementInfoGenerate()//����Ԫ����Ϣ�������
	{
		if (!(color[1] == 0 && color[2] == 0 && color[3] == 0 && color[4] == 0))
			printf("color(c=[%lf,%lf,%lf,%lf])", color[1], color[2], color[3], color[4]);
		if (!(mirror[1] == 0 && mirror[2] == 0 && mirror[3] == 0))
			printf("mirror([%lf,%lf,%lf])", mirror[1], mirror[2], mirror[3]);
		if (!(translate[1] == 0 && translate[2] == 0 && translate[3] == 0))
			printf("translate([%lf,%lf,%lf])", translate[1], translate[2], translate[3]);
		if (!(rotate[1] == 0 && rotate[2] == 0 && rotate[3] == 0 && rotate[4] == 0))
			printf("rotate(v=[%lf,%lf,%lf],a=%lf)", rotate[1], rotate[2], rotate[3], rotate[4]);
		if (!(resize[1] == 0 && resize[2] == 0 && resize[3] == 0 && rsauto == false))
		{
			printf("scale([%lf,%lf,%lf],", resize[1], resize[2], resize[3]);
			if (rsauto == true)printf("auto=true)");
			else printf("auto=false)");
		}
		if (!(scale[1] == 0 && scale[2] == 0 && scale[3] == 0))
			printf("scale([%lf,%lf,%lf])", scale[1], scale[2], scale[3]);
		if (type == 1)
			printf("cube([%lf,%lf,%lf])", cdd[1], cdd[2], cdd[3]);
		if (type == 2)
			printf("sphere(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)", cdd[1], cdd[2], cdd[3], cdd[4]);
		if (type == 3)
			printf("cylinder(h=%lf,r1=%lf,r2=%lf,$fa=%lf,$fs=%lf,$fn=%lf)", cdd[1], cdd[2], cdd[3], cdd[4], cdd[5], cdd[6]);
		if (type == 4)
			printf("square(size=[%lf,%lf])", cdd[1], cdd[2]);
		if (type == 5)
			printf("circle(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)", cdd[1], cdd[2], cdd[3], cdd[4]);
		printf(";");
	}
};
struct BridgeInfo
{
	Dot d1, d2;
};