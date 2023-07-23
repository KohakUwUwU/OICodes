#include<stdio.h>
float p,w,s;
inline float judge()
{
	if(s<250)return 1;
	else if(s<500)return 0.98;
	else if(s<1000)return 0.95;
	else if(s<2000)return 0.92;
	else if(s<3000)return 0.90;
	else return 0.85;
}
int main()
{
	scanf("%f%f%f",&p,&w,&s);
	printf("freight=%.2f",p*w*s*judge());
}
