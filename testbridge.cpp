//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Element
{
	//注：默认下元素中心处于原点，此处省略center参数
	//注：暂不支持多边形和多面体
	//注：支持的修饰符如变量所示，没有适配完，请谅解 
	int type;//元素类型
	double cdd[8];//元素参数candidate
	double scale[4];
	double resize[4];bool rsauto;
	double rotate[5];
	double translate[4];
	double mirror[4];
	double color[5];
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
		if(!(color[1]==0&&color[2]==0&&color[3]==0&&color[4]==0))printf("color(c=[%lf,%lf,%lf,%lf])",scale[1],scale[2],scale[3],scale[4]);
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
		if(type==1)printf("cube([%lf,%lf,%lf],center=true)",cdd[1],cdd[2],cdd[3]);
		if(type==2)printf("sphere(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4]);
		if(type==3)printf("cylinder(h=%lf,r1=%lf,r2=%lf,center=true,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4],cdd[5],cdd[6]);
		if(type==4)printf("square(size=[%lf,%lf],center=true)",cdd[1],cdd[2]);
		if(type==5)printf("circle(r=%lf,$fa=%lf,$fs=%lf,$fn=%lf)",cdd[1],cdd[2],cdd[3],cdd[4]);
	printf(";");
	}
};
struct BridgeInfo
{
	double start1[4];
	double start2[4];
	double end1[4];
	double end2[4];
};
const int N=1e5+7;//总元素上限 
const int M=2e5+7;//总桥数上限 
Element Data[N];//元素内存池 
int ElementCnt;//元素个数
BridgeInfo bridge[M];//桥梁信息内存池
int BridgeCnt;//桥梁个数 
bool vis[N];
inline void OptOut(int i)
{
	if(Data[i].to)
	{
		if(Data[i].opt==1)printf("union(){");
		if(Data[i].opt==2)printf("difference(){");
		if(Data[i].opt==3)printf("intersection(){");
	}
	Data[i].ElementInfoGenerate();
	if(Data[i].to)OptOut(Data[i].to);
	if(Data[i].to)printf("}");
}
inline void Output()
{
	for(int i=1;i<=ElementCnt;i++)
	{
		if(vis[i])continue;
		OptOut(i);//递归调用
		printf("\n"); 
	}
}
signed main()
{
	/*
	示例 
	ElementCnt++;
	Data[1].type=1;
	Data[1].cdd[1]=Data[1].cdd[3]=Data[1].cdd[2]=1;
	Data[1].scale[1]=Data[1].scale[1]=Data[1].scale[1]=2;
	Data[1].to=2;
	Data[1].opt=1;
	ElementCnt++;
	Data[2].type=1;
	Data[2].cdd[1]=Data[2].cdd[3]=Data[2].cdd[2]=2;
	Data[2].scale[1]=Data[2].scale[1]=Data[2].scale[1]=3;
	vis[2]=1;
	Output();
	*/
	
	return 0;
}

