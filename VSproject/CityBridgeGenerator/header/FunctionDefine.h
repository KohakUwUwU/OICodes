#pragma once
#include"StdConstDefine.h"
#include"VarDefine.h"
#include"TypeDefine.h"
inline bool Ranginglegal(Ranging a)
{
	return a.st <= a.ed;
}
inline Ranging RangingI(Ranging a, Ranging b)//交集 
{
	if (!Ranginglegal(a) || !Ranginglegal(b))return EmptyRanging;
	if (a.st > b.ed || a.ed < b.st)return EmptyRanging;
	return { max(a.st, b.st), min(a.ed, b.ed) };
}
inline int xxRanging(Line a, Ranging ar, Line b, Ranging br)
{
	if (a == b)return HOMO;
	if (a.k == b.k)return 0;
	Dot d = a.X(b);
	if (ar.st <= d.x && d.x <= ar.ed && br.st <= d.x && d.x <= br.ed)return 1;
	else return 0;
}
inline int xoRanging(Line a, Ranging ar, Circle o)
{
	int cnt = 0;
	DoubleDot _2d = o.oldot(a);
	Dot dot1 = _2d.dot1, dot2 = _2d.dot2;
	if (ar.st <= dot1.x && dot1.x <= ar.ed)cnt++;
	if (ar.st <= dot2.x && dot2.x <= ar.ed)cnt++;
	return cnt;
}
Line GenerateLine(Dot d1, Dot d2)
{
	double k = (d2.y - d1.y) / (d2.x - d1.x);
	double b = d1.y - d1.x * k;
	return { k, b };
}
inline double DtoR(double d)//角度转弧度
{
	return d / 180.0 * PI;
}
inline double RtoD(double r)//弧度转角度 
{
	return r / PI * 180;
}
Line Line3Dto2D(Line3D l)
{
	Line ans;
	ans.k = l.m / l.n;
	ans.b = l.y0 - l.x0 * ans.k;
	return ans;
}
inline double Dis3D(Dot3D d1, Dot3D d2)
{
	return sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y) + (d1.z - d2.z) * (d1.z - d2.z));
}
inline double DotLine(Line3D l, Ranging r, Dot3D d)
{
	double tst = l.XtoT(r.st);
	double ted = l.XtoT(r.ed);
	Dot3D Center = d;
	Dot3D d1 = { l.TtoX(tst),l.TtoY(tst),l.TtoZ(tst) };
	Dot3D d2 = { l.TtoX(ted),l.TtoY(ted),l.TtoZ(ted) };
	double Center_d1 = Dis3D(Center, d1);
	double d1_d2 = Dis3D(d1, d2);
	double Center_d2 = Dis3D(Center, d2);
	double p = (Center_d1 + Center_d2 + d1_d2) / 2.0;
	double S = sqrt(p * (p - d1_d2) * (p - Center_d1) * (p - Center_d2));
	double H = 2.0 * S / d1_d2;
}
inline bool cmp(Dot x, Dot y)
{
	if (x.x != y.x)return x.x > y.x;
	return x.y > y.y;
}
inline int LineCube(Line3D l, Ranging r, Cube c)
{
	double tst = l.XtoT(r.st);
	double ted = l.XtoT(r.ed);
	double yst = l.TtoY(tst);
	double yed = l.TtoY(ted);
	Dot d1 = { c.x,c.y };
	Dot d2 = { c.x + c.b * cos(DtoR(c.spin + 90.0)),c.y + c.b * sin(DtoR(c.spin + 90.0)) };
	Dot d3 = { c.x + c.a * cos(DtoR(c.spin)),c.y + c.a * sin(DtoR(c.spin)) };
	Dot d4 = { d2.x + d3.x - d1.x,d2.y + d3.y - d1.y };
	//顺时针1243
	Line l2d = Line3Dto2D(l);
	Line ll[5];
	ll[1] = GenerateLine(d1, d2);
	ll[2] = GenerateLine(d2, d4);
	ll[3] = GenerateLine(d4, d3);
	ll[4] = GenerateLine(d3, d1);
	if (ll[1] == l2d || ll[2] == l2d || ll[3] == l2d || ll[4] == l2d)return HOMO;
	Dot dd[5];
	int timer = 0;
	if (xxRanging(ll[1], { d1.x, d2.x }, l2d, { 0, HOMO }))dd[++timer] = l2d.X(ll[1]);
	if (xxRanging(ll[2], { d2.x, d4.x }, l2d, { 0, HOMO }))dd[++timer] = l2d.X(ll[2]);
	if (xxRanging(ll[3], { d4.x, d3.x }, l2d, { 0, HOMO }))dd[++timer] = l2d.X(ll[3]);
	if (xxRanging(ll[4], { d3.x, d1.x }, l2d, { 0, HOMO }))dd[++timer] = l2d.X(ll[4]);
	sort(dd + 1, dd + 1 + timer, cmp);
	for (int i = 2; i <= timer; i++)
	{
		if (abs(dd[i].x - dd[i - 1].x) <= EPS && abs(dd[i].y - dd[i - 1].y) <= EPS)dd[i] = { 0,0 };
	}
	for (int i = 1; i <= timer; i++)
	{
		if (!(r.st <= dd[i].x && dd[i].x <= r.ed))dd[i] = { 0,0 };
	}
	sort(dd + 1, dd + 5, cmp);
	timer = 1;
	while (dd[timer + 1].x != 0 || dd[timer + 1].y != 0)timer++;
	if (timer == 0)return 0;
	if (timer == 1)
	{
		double zz = l.TtoZ(l.XtoT(dd[1].x));
		if (zz - c.z - c.c > EPS)return 0;
		return 1;
	}
	if (timer == 2)
	{
		int cnt = 0;
		for (int i = 1; i <= 2; i++)
		{
			double zz = l.TtoZ(l.XtoT(dd[i].x));
			if (zz - c.z - c.c <= EPS)cnt++;
		}
		return cnt;
	}
}
inline int LineSphere(Line3D l, Ranging r, Sphere s)
{
	double tst = l.XtoT(r.st);
	double ted = l.XtoT(r.ed);
	Dot3D Center = { s.x,s.y,s.z };
	Dot3D d1 = { l.TtoX(tst),l.TtoY(tst),l.TtoZ(tst) };
	Dot3D d2 = { l.TtoX(ted),l.TtoY(ted),l.TtoZ(ted) };
	double Center_d1 = Dis3D(Center, d1);
	double d1_d2 = Dis3D(d1, d2);
	double Center_d2 = Dis3D(Center, d2);
	double p = (Center_d1 + Center_d2 + d1_d2) / 2.0;
	double S = sqrt(p * (p - d1_d2) * (p - Center_d1) * (p - Center_d2));
	double H = 2.0 * S / d1_d2;
	double distance = 0;
	if (H < Center_d1 && H < Center_d2)distance = min(Center_d1, Center_d2);
	else distance = H;
	if (abs(distance - s.r) <= EPS)return 1;
	if (distance < s.r)return 2;
	return 0;
}
inline int LineCylinder(Line3D l, Ranging r, Cylinder c)
{

}
inline void getXYRanging()
{
	Minx = Miny = Minz = HOMO;
	Maxx = Maxy = Maxz = 0;
	for (int i = 1; i <= ElementCnt; i++)
	{
		xlow[i] = ylow[i] = zlow[i] = HOMO;
		xhigh[i] = yhigh[i] = zhigh[i] = 0;
		if (Data[i].type == 1)
		{
			double dot1x = Data[i].translate[1];
			double dot1y = Data[i].translate[2];
			double dot2x = Data[i].translate[1] + Data[i].cdd[2] * cos(DtoR(Data[i].rotate[3] + 90.0));
			double dot2y = Data[i].translate[2] + Data[i].cdd[2] * sin(DtoR(Data[i].rotate[3] + 90.0));
			double dot3x = Data[i].translate[1] + Data[i].cdd[1] * cos(DtoR(Data[i].rotate[3]));
			double dot3y = Data[i].translate[2] + Data[i].cdd[1] * sin(DtoR(Data[i].rotate[3]));
			double dot4x = dot2x + dot3x - dot1x;
			double dot4y = dot2y + dot3y - dot1y;
			xlow[i] = min(xlow[i], dot1x);
			xlow[i] = min(xlow[i], dot2x);
			xlow[i] = min(xlow[i], dot3x);
			xlow[i] = min(xlow[i], dot4x);
			ylow[i] = min(ylow[i], dot1y);
			ylow[i] = min(ylow[i], dot2y);
			ylow[i] = min(ylow[i], dot3y);
			ylow[i] = min(ylow[i], dot4y);
			xhigh[i] = max(xhigh[i], dot1x);
			xhigh[i] = max(xhigh[i], dot2x);
			xhigh[i] = max(xhigh[i], dot3x);
			xhigh[i] = max(xhigh[i], dot4x);
			yhigh[i] = max(yhigh[i], dot1y);
			yhigh[i] = max(yhigh[i], dot2y);
			yhigh[i] = max(yhigh[i], dot3y);
			yhigh[i] = max(yhigh[i], dot4y);
			zlow[i] = Data[i].translate[3];
			zhigh[i] = Data[i].translate[3] + Data[i].cdd[3];
		}
		if (Data[i].type == 2)
		{
			xlow[i] = Data[i].translate[1] - Data[i].cdd[1];
			xhigh[i] = Data[i].translate[1] + Data[i].cdd[1];
			ylow[i] = Data[i].translate[2] - Data[i].cdd[1];
			yhigh[i] = Data[i].translate[2] + Data[i].cdd[1];
			zlow[i] = Data[i].translate[3] - Data[i].cdd[1];
			zhigh[i] = Data[i].translate[3] + Data[i].cdd[1];
		}
		if (Data[i].type == 3)
		{
			double r = max(Data[i].cdd[2], Data[i].cdd[3]);
			xlow[i] = Data[i].translate[1] - r;
			xhigh[i] = Data[i].translate[1] + r;
			ylow[i] = Data[i].translate[2] - r;
			yhigh[i] = Data[i].translate[2] + r;
			zlow[i] = Data[i].translate[3];
			zhigh[i] = Data[i].translate[3] + Data[i].cdd[1];
		}
		Minx = min(Minx, xlow[i]);
		Maxx = max(Maxx, xhigh[i]);
		Miny = min(Miny, ylow[i]);
		Maxy = max(Maxy, yhigh[i]);
		Minz = min(Minz, zlow[i]);
		Maxz = max(Maxz, zhigh[i]);
	}
	bl = ceil(sqrt(min(Maxx - Minx, Maxy - Miny)));
	sx = floor(Minx); sy = floor(Miny);
	ex = ceil(Maxx); ey = ceil(Maxy);
}
inline void getHousebl()
{
	for (int i = 1; i <= ElementCnt; i++)
	{
		int mnx = floor(xlow[i]); stblx[i] = (mnx - sx) / bl + 1;
		int mny = floor(ylow[i]); stbly[i] = (mny - sy) / bl + 1;
		int mxx = ceil(xhigh[i]); edblx[i] = (mxx - ex) / bl + 1;
		int mxy = ceil(yhigh[i]); edbly[i] = (mxy - ey) / bl + 1;
		for (int j = stblx[i]; j <= edblx[i]; j++)
		{
			for (int k = stbly[i]; k <= edbly[i]; k++)
			{
				blit[j][k].push_back(i);
			}
		}
	}
}
inline int CheckLink()
{
	for (int i = 1; i <= ElementCnt; i++)
	{
		if (vis[i])
		{
			if (runed[i])return 1;
			runed[i] = 1;
			int j = i;
			while (Data[j].to)
			{
				j = Data[j].to;
				runed[j] = 1;
			}
		}
	}
	return 0;
}
inline double LowestPoint(int id)
{
	return Data[id].translate[2];
}
inline int CheckOnFloor()
{
	//建筑分组存入vector 
	for (int i = 1; i <= ElementCnt; i++)
	{
		if (vis[i])
		{
			++ItemCnt;
			Item[ItemCnt].push_back(i);
			int j = i;
			while (Data[j].to)
			{
				j = Data[j].to;
				Item[ItemCnt].push_back(j);
			}
		}
	}
	for (int i = 1; i <= ItemCnt; i++)
	{
		double lowest = HOMO;
		for (int j = 0; j < Item[i].size(); i++)
		{
			lowest = min(lowest, LowestPoint(Item[i][j]));
		}
		if (abs(lowest) > EPS)return 1;
	}
	return 0;
}
inline void Bridging()
{

}
inline int Process()
{
	if (CheckLink())
	{
		cout << "Link Error!" << '\n';
		return 1;
	}
	if (CheckOnFloor())
	{
		cout << "Not On Floor!" << '\n';
		return 1;
	}
	getXYRanging();
	getHousebl();
	Bridging();
}
inline void OptOut(int i)
{
	if (Data[i].to)
	{
		if (Data[i].opt == 1)printf("union(){");
		if (Data[i].opt == 2)printf("difference(){");
		if (Data[i].opt == 3)printf("intersection(){");
	}
	Data[i].ElementInfoGenerate();
	if (Data[i].to)OptOut(Data[i].to);
	if (Data[i].to)printf("}");
}
inline void Output()
{
	for (int i = 1; i <= ElementCnt; i++)
	{
		if (vis[i])continue;
		OptOut(i);//递归调用
		printf("\n");
	}
}