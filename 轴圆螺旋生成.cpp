//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5;
double X,Y,Z,R,mode,cN,r;
//-----���������-----
double circle[N][2];//��Բ�˶����� x y 
double rd[N][3];//�����˶����� x y z
//-----����������-----
//����mode, �ɱ��� 1 ��ά�����겻�䣬����������������
//����round, ÿ��תһ�ܣ��н�����360/cN 
//----���Ǻ�������----
const long double pi=3.14159265358979;
inline double trans(double angle)
{
	return angle*pi/180.0000;
}
signed main()
{
	printf("��������ԲԲ������ X Y Z\n");
	scanf("%lf%lf%lf",&X,&Y,&Z);
	printf("��������Բ�뾶��С R\n");
	scanf("%lf",&R);
	printf("��������Բ�γ��� 1:x y 2:y z 3:x z\n");
	scanf("%lf",&mode);
	printf("���������߹���תȦ�� x\n");
	scanf("%lf",&cN);
	printf("���������߹���ת�뾶 x\n");
	scanf("%lf",&r);
	printf("ע:�ӣ���������ʼ��ʱ������");
	//-----����circle-----
	printf("������Բ\n");
	for(int i=0;i<8*cN;i++)
	{
		double gamma=360.0*(double)i/(double)(8.0*double(cN));
		circle[i][0]=double(R)*cos(trans(gamma));
		circle[i][1]=double(R)*sin(trans(gamma));
		if(mode==1)printf("%lf %lf %lf\n",circle[i][0]+X,circle[i][1]+Y,Z);
		if(mode==2)printf("%lf %lf %lf\n",X,circle[i][0]+Y,circle[i][1]+Z);
		if(mode==3)printf("%lf %lf %lf\n",circle[i][0]+X,Y,circle[i][1]+Z);
	}
	//�������ɾ�Ϊ����Բ�ڲ���ʼ˳ʱ����ת�߹� 
	//-----����y����------
	double posY[8]={0,sqrt(2)/(double)2.0,1,sqrt(2)/(double)2.0,0,-sqrt(2)/(double)2.0,-1,-sqrt(2)/(double)2.0};
	double posX[8]={-1,-sqrt(2)/(double)2.0,0,sqrt(2)/(double)2.0,1,sqrt(2)/(double)2.0,0,-sqrt(2)/(double)2.0}; 
	for(int i=0;i<8*cN;i++)rd[i][1]+=r*posY[i%8];
	//-----����xz����-----
	for(int i=0;i<8*cN;i++)
	{
		double gamma=360.0*(double)i/(double)(8.0*double(cN));
		rd[i][0]=posX[i%8]*cos(trans(gamma))*r;
		rd[i][2]=posX[i%8]*sin(trans(gamma))*r;
	}
	//xz(0,2)������Զͬ�� , xz(0,2)��circle y(1)������circle���� 
	switch((int)(mode))
	{
	case 1:
		printf("1��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],circle[i][1]+Y+rd[i][2],Z+rd[i][1]);
		printf("2��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],circle[i][1]+Y-rd[i][2],Z+rd[i][1]);
		printf("3��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],circle[i][1]+Y+rd[i][2],Z-rd[i][1]);
		printf("4��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],circle[i][1]+Y-rd[i][2],Z-rd[i][1]);
		break;
	case 2:
		printf("1��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X+rd[i][1],circle[i][0]+Y+rd[i][0],circle[i][1]+Z+rd[i][2]);
		printf("2��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X-rd[i][1],circle[i][0]+Y+rd[i][0],circle[i][1]+Z+rd[i][2]);
		printf("3��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X+rd[i][1],circle[i][0]+Y-rd[i][0],circle[i][1]+Z-rd[i][2]);
		printf("4��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",X-rd[i][1],circle[i][0]+Y-rd[i][0],circle[i][1]+Z-rd[i][2]);
		break;
	case 3:
		printf("1��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],Y+rd[i][1],circle[i][1]+Z+rd[i][2]);
		printf("2��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X+rd[i][0],Y-rd[i][1],circle[i][1]+Z+rd[i][2]);
		printf("3��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],Y+rd[i][1],circle[i][1]+Z-rd[i][2]);
		printf("4��:\n");for(int i=0;i<8*cN;i++)printf("%lf %lf %lf\n",circle[i][0]+X-rd[i][0],Y-rd[i][1],circle[i][1]+Z-rd[i][2]);
		break;
	}
	int iii;
	cin>>iii; 
	return 0;
}

