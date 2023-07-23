#include <iostream>
#include <cmath>
#include <map>
#define r register
#define ull unsigned long long
using namespace std;
int n;
map<int,map<int,ull> >g,l;
int i,j,k,x,y,z;
ull ans;
#define ans1(p,q,r) l[p][r]*g[q][r]/g[p][q]
//inline long long gcd(long long a,long long b) 
//{
//    if(!a) return b;
//    if(!b) return a;
//    if(!(a | 1) && !(b | 1)) return gcd(a >> 1, b >> 1) << 1;
//    else if(!(a | 1)) return gcd(a >> 1, b);
//    else if(!(b | 1)) return gcd(a, b >> 1);
//    return gcd(abs(a - b), min(a, b));
//}
inline ull gcd(ull a,ull b) {
    while(b^=a^=b^=a%=b);
    return a;
}
inline ull lcm(ull a,ull b)
{
    if(a>b)return a*b/g[b][a];
    return a*b/g[a][b];
}
inline ull lcm1(ull a,ull b)
{
    return a*b/gcd(a,b);
}
inline ull judge(ull a,ull b,ull c)
{
	if(a!=b&&a!=c&&b!=c)return 6;
	if(a==b&&a==c)return 1;
	return 3;
}
int main() {
	
    for(i=1;i<=1000000;i++)
    {
    	printf("Process:%d\n",i);
    	for(j=i;j<=1000000;j++)
            g[i][j]=gcd(i,j),g[j][i]=g[i][j],l[i][j]=lcm(i,j),l[j][i]=l[i][j];
	}
    for(int bb=1;bb<=1000000;bb++)
    {
    	n=bb;
    for(x=1;x<=n;x++)
        for(y=x;y<=n;y++)
            for(z=y;z<=n;z++)
            	ans+=judge(x,y,z)*lcm1(lcm1(lcm1(ans1(x,y,z),ans1(x,z,y)),lcm1(ans1(y,x,z),ans1(y,z,x))),lcm1(ans1(z,x,y),ans1(z,y,x)));
//    for(x=1;x<=n;x++)
//    	for(y=1;y<=n;y++)
//    		for(z=1;z<=n;z++)
//				ans+=lcm1(lcm1(lcm1(ans1(x,y,z),ans1(x,z,y)),lcm1(ans1(y,x,z),ans1(y,z,x))),lcm1(ans1(z,x,y),ans1(z,y,x)));
    cout<<ans<<",";
	}
}

