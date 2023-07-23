#pragma once
#include"Fx3D.hpp" 
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
	double resize[4];bool rsauto;//Ŀǰ���� 
	double rotate[5];//Ŀǰ����cube x,y����ת��sphere��ת��cylinder x,y��ת
	double translate[4];
	double mirror[4];//Ŀǰ���� 
	double color[5];//���Ƽ�ʹ�� 
	int to;//Ŀ��Ԫ�� 
	int opt;//��Ŀ��Ԫ�صĲ���������ǰԪ����ǰ 
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
	void ElementInfoGenerate()//����Ԫ����Ϣ�������
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
Ԫ�ز�����
���wiki���������output.hpp 

---------------------- 

���η���
scale:�ֱ��ʾx,y,z�ᰴ������������ֹʹ�ø���������mirror 
resize:�ֱ��ʾx,y,z�������ָ����С 
rotate:��ʾ��(x,y,z)����תtheta���� 
translate:�ֱ��ʾx,y,z���ƶ����� 
mirror:��ʾ����ƽ�淨����(x,y,z) 
color:�ֱ��ʾr,g,b,a��ɫ
���η����ȼ��������£� 

--------------------- 

opt��
1 union ����
2 difference ����
3 intersection ����

--------------------- 

�ŵ�����յ�����������߶α�ʾ
ǿ��Ҫ���ŵ�������յ��ڽ�����ǽ����

--------------------- 
*/
