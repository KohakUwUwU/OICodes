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
            //�ǵ�ʹ��while������if��Ҫһ������
	}
	for (int i=1;i<=10000;i++)  //���
    	if (a[i]!=0)
    		printf("%d %d\n",i,a[i]);
}
