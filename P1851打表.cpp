#include<cstdio>
int a[17]={284,1210,2924,5564,6386,10856,14595,18416,66992,71145,76084,87633,88730};
int b[17]={220,1184,2620,5020,6232,10744,12285,17296,66928,67095,63020,69615,79750};
int s;
int main()
{
	scanf("%d",&s);
	for(int i=0;i<=15;i++)
	{
		if(b[i]>=s){printf("%d %d",b[i],a[i]);return 0;}
        	//小数大于s，输出小数，再大数
		if(a[i]>=s){printf("%d %d",a[i],b[i]);return 0;}
        	//大数大于s，输出大数，再小数
	}
    
	return 0;
}
