#include<stdio.h>
#define R register
#define ull unsigned long long
#define ru ull
inline ru gcd(ru& a,ru& b,ru& c) {
    for(;b^=a^=b^=a%=b;);
    for(;c^=a^=c^=a%=c;);
    return a;
}
#define judge(a,b,c) ull((a^b&&a^c&&b^c)?6:(!(a^b||a^c)?1:3)) 
int main()
{
	ru i=1,j,k,n;
	ru tmp,sum=0;
	scanf("%d",&n);
	for(;i<=n;i++)for(j=i;j<=n;j++)for(k=j;k<=n;k++)
	{
		tmp=gcd(i,j,k);
		sum+=judge(i,j,k)*((i*j*k)/(tmp*tmp));
	}
	printf("%ld",sum);
}
