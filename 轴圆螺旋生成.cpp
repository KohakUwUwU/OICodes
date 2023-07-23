//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5;
double X,Y,Z,R,mode,cN,r;
//-----贡献组变量-----
double circle[N][2];//轴圆运动贡献 x y 
double rd[N][3];//绕轴运动贡献 x y z
//-----分析の内容-----
//对于mode, 可保持 1 个维度坐标不变，对其他两个做贡献
//对于round, 每旋转一周，夹角增加360/cN 
//----三角函数计算----
const long double pi=3.14159265358979;
inline double trans(double angle)
{
	return angle*pi/180.0000;
}
signed main()
{
	printf("请输入轴圆圆心坐标 X Y Z\n");
	scanf("%lf%lf%lf",&X,&Y,&Z);
	printf("请输入轴圆半径大小 R\n");
	scanf("%lf",&R);
	printf("请输入轴圆形成面 1:x y 2:y z 3:x z\n");
	scanf("%lf",&mode);
	printf("请输入四线股旋转圈数 x\n");
	scanf("%lf",&cN);
	printf("请输入四线股旋转半径 x\n");
	scanf("%lf",&r);
	printf("注:从？轴正方向开始逆时针生成");
	//-----生成circle-----
	printf("生成轴圆\n");
	for(int i=0;i<8*cN;i++)
	{
		double gamma=360.0*(double)i/(double)(8.0*double(cN));
		circle[i][0]=double(R)*cos(trans(gamma));
		circle[i][1]=double(R)*sin(trans(gamma));
		if(mode==1)printf("%lf %lf %lf\n",circle[i][0]+X,circle[i][1]+Y,Z);
		if(mode==2)printf("%lf %lf %lf\n",X,circle[i][0]+Y,circle[i][1]+Z);
		if(mode==3)printf("%lf %lf %lf\n",circle[i][0]+X,Y,circle[i][1]+Z);
	}
	//贡献生成均为从轴圆内部开始顺时针旋转线股 
	//-----生成y参数------
	double posY[8]={0,sqrt(2)/(double)2.0,1,sqrt(2)/(double)2.0,0,-sqrt(2)/(double)2.0,-1,-sqrt(2)/(double)2.0};
	double posX[8]={-1,-sqrt(2)/(double)2.0,0,sqrt(2)/(double)2.0,1,sqrt(2)/(double)2.0,0,-sqrt(2)/(double)2.0}; 
	for(int i=0;i<8*cN;i++)rd[i][1]+=r*posY[i%8];
	//-----生成xz参数-----
	for(int i=0;i<8*cN;i++)
	{
		double gamma=360.0*(double)i/(double)(8.0*double(cN));
		rd[i][0]=posX[i%8]*cos(trans(gamma))*r;
		rd[i][2]=posX[i%8]*sin(trans(gamma))*r;
	}
	//xz(0,2)贡献永远同号 , xz(0,2)跟circle y(1)中永无circle贡献 
	switch((int)(mode))
	{
	case 1:
		printf("1号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],circle[i][1]+Y+rd[i][2],Z+rd[i][1]);
		printf("2号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],circle[i][1]+Y-rd[i][2],Z+rd[i][1]);
		printf("3号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],circle[i][1]+Y+rd[i][2],Z-rd[i][1]);
		printf("4号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],circle[i][1]+Y-rd[i][2],Z-rd[i][1]);
		break;
	case 2:
		printf("1号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X+rd[i][1],circle[i][0]+Y+rd[i][0],circle[i][1]+Z+rd[i][2]);
		printf("2号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X-rd[i][1],circle[i][0]+Y+rd[i][0],circle[i][1]+Z+rd[i][2]);
		printf("3号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X+rd[i][1],circle[i][0]+Y-rd[i][0],circle[i][1]+Z-rd[i][2]);
		printf("4号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X-rd[i][1],circle[i][0]+Y-rd[i][0],circle[i][1]+Z-rd[i][2]);
		break;
	case 3:
		printf("1号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],Y+rd[i][1],circle[i][1]+Z+rd[i][2]);
		printf("2号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],Y-rd[i][1],circle[i][1]+Z+rd[i][2]);
		printf("3号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],Y+rd[i][1],circle[i][1]+Z-rd[i][2]);
		printf("4号:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],Y-rd[i][1],circle[i][1]+Z-rd[i][2]);
		break;
	}
	int iii;
	cin>>iii; 
	return 0;
}

