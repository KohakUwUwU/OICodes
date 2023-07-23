#include<stdio.h>
int i=1,j,k,n,tmp;
long long sum;
inline int gcd(register int a,register int b,register int c) {
    while(b^=a^=b^=a%=b);
    while(c^=a^=c^=a%=c);
    return a;
}
inline int judge(register int a,register int b,register int c)
{
	if(a^b&&a^c&&b^c)return 6;
	if(!(a^b||a^c))return 1;
	return 3;
}
int main()
{
	scanf("%d",&n);
	for(;i<=n;i++)for(j=i;j<=n;j++)for(k=j;k<=n;k++)tmp=gcd(i,j,k),sum+=judge(i,j,k)*i*j*k/tmp/tmp;
	printf("%ld",sum);
}
