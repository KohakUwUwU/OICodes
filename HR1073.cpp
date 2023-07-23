#include<stdio.h>
inline int gcd(int a,int b) {
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
	int a,b,ansa,ansb;
	while(scanf("%d%d",&a,&b))
	{
		if(a==ansa&&b==ansb)return 0;
		printf("%d\n",gcd(a,b));
		ansa=a;ansb=b;
	}
}
