#include<stdio.h>
int a,b,c;
inline void swap(int* kk,int* dd)
{
	int mm=*kk;
	*kk=*dd;
	*dd=mm;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)swap(&a,&b);
	if(a>c)swap(&a,&c);
	if(b>c)swap(&b,&c);
	printf("%d %d %d\n",a,b,c);
}
