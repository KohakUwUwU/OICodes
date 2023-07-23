#pragma once
#include"Fx3D.hpp" 
struct Element
{
	//注：默认下cube center=false sphere在原点 
	//注：暂不支持多边形和多面体
	//注：支持的修饰符如变量所示，没有适配完，请谅解
	//注：2D模型目前禁用 
	//注：只能把物体放在第一象限
	//注：一组建筑必须连在一起！
	int type;//元素类型 
	double cdd[8];//元素参数candidate
	double scale[4];//目前禁用 
	double resize[4];bool rsauto;//目前禁用 
	double rotate[5];//目前禁用cube x,y轴旋转，sphere旋转，cylinder x,y旋转
	double translate[4];
	double mirror[4];//目前禁用 
	double color[5];//不推荐使用 
	int to;//目标元素 
	int opt;//与目标元素的操作符，当前元素在前 
	Element()
	{
		type=0;
		memset(cdd,0,sizeof(cdd));
		memset(scale,0,sizeof(scale));
		memset(resize,0,sizeof(resize));rsauto=false;
		memset(rotate,0,sizeof(rotate));
		memset(translate,0,sizeof(translate));
		memset(mirror,0,sizeof(mirror));
		memset(color,0,sizeof(color));
		to=0;
		opt=0;
	}
	void ElementInfoGenerate()//单个元素信息语句生成
	{
		if(!(color[1]==0&&color[2]==0&&color[3]==0&&color[4]==0))printf("color(c=[%lf,%lf,%lf,%lf])",color[1],color[2],color[3],color[4]);
		if(!(mirror[1]==0&&mirror[2]==0&&mirror[3]==0))printf("mirror([%lf,%lf,%lf])",mirror[1],mirror[2],mirror[3]);
		if(!(translate[1]==0&&translate[2]==0&&translate[3]==0))printf("translate([%lf,%lf,%lf])",translate[1],translate[2],translate[3]);
		if(!(rotate[1]==0&&rotate[2]==0&&rotate[3]==0&&rotate[4]==0))printf("rotate(v=[%lf,%lf,%lf],a=%lf)",rotate[1],rotate[2],rotate[3],rotate[4]);
		if(!(resize[1]==0&&resize[2]==0&&resize[3]==0&&rsauto==false))
		{
			printf("scale([%lf,%lf,%lf],",resize[1],resize[2],resize[3]);
			if(rsauto==true)printf("auto=true)");
			else printf("auto=false)");
		}
		if(!(scale[1]==0&&scale[2]==0&&scale[3]==0))printf("scale([%lf,%lf,%lf])",scale[1],scale[2],scale[3]);
		if(type==1)printf("cube([%lf,%lf,%lf])",cdd[1],cdd[2],cdd[3]);
		if(type==2)printf("sphere(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4]);
		if(type==3)printf("cylinder(h=%lf,r1=%lf,r2=%lf,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4],cdd[5],cdd[6]);
		if(type==4)printf("square(size=[%lf,%lf])",cdd[1],cdd[2]);
		if(type==5)printf("circle(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4]);
	printf(";");
	}
};
struct BridgeInfo
{
	Dot d1,d2;
};
/*
元素参数：
请见wiki网参数表或output.hpp 

---------------------- 

修饰符：
scale:分别表示x,y,z轴按比例放缩，禁止使用负数，请用mirror 
resize:分别表示x,y,z轴放缩到指定大小 
rotate:表示绕(x,y,z)轴旋转theta度数 
translate:分别表示x,y,z轴移动距离 
mirror:表示镜像平面法向量(x,y,z) 
color:分别表示r,g,b,a颜色
修饰符优先级从上至下！ 

--------------------- 

opt：
1 union 并集
2 difference 减集
3 intersection 交集

--------------------- 

桥的起点终点参数由两条线段表示
强制要求桥的起点与终点在建筑的墙面上

--------------------- 
*/
