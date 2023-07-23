#include<stdio.h>
int a[10001]={},n;
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
	 	int i2=i;
		for (int j=2;j<=i;j++)
			while (i2%j==0) {a[j]++; i2/=j;} 
            //记得使用while，不是if，要一除到底
	}
	for (int i=1;i<=10000;i++)  //输出
    	if (a[i]!=0)
    		printf("%d %d\n",i,a[i]);
}
