#include<stdio.h>
long long n,x=1,ans=1;
int main(){
	scanf("%ld",&n);
	while(ans<n)ans+=x<<=1;
	printf("%ld",ans<<1);
}
