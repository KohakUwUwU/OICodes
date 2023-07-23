#include<cstdio>
#define ll long long
ll k,n,tmp;
inline ll seat(ll x,ll y)
{
	if(x-y+2*k+2>0)return 0;
	if((y-x+1)%2)return (seat(x,(y+x)>>1)<<1)+1;
	else return seat(x,(x+y)>>1)+seat((x+y)>>1,y)+1;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	tmp=seat(1,n+1)+1;
	printf("%lld",tmp);
	return 0;
}//Ã»ÓÐac 
