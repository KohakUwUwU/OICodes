#include <iostream>
#include <map>
#define r register
#define ull unsigned long long
using namespace std;
map<int,map<int,ull> >g,l;
int n,i,j,k,x,y,z;
ull ans;
#define ans1(p,q,r) l[p][r]*g[q][r]/g[p][q]
inline ull gcd(r ull a,r ull b) {
    while(b^=a^=b^=a%=b);
    return a;
}
inline ull lcm(r ull a,r ull b)
{
    if(a>b)return a*b/g[b][a];
    return a*b/g[a][b];
}
inline ull lcm1(r ull a,r ull b)
{
    return a*b/gcd(a,b);
}
inline ull judge(r ull a,r ull b,r ull c)
{
	if(a!=b&&a!=c&&b!=c)return 6;
	if(a==b&&a==c)return 1;
	return 3;
}
int main() {
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            g[i][j]=gcd(i,j),g[j][i]=g[i][j],l[i][j]=lcm(i,j),l[j][i]=l[i][j];
    for(x=1;x<=n;x++)
        for(y=x;y<=n;y++)
            for(z=y;z<=n;z++)
            	ans+=judge(x,y,z)*lcm1(lcm1(lcm1(ans1(x,y,z),ans1(x,z,y)),lcm1(ans1(y,x,z),ans1(y,z,x))),lcm1(ans1(z,x,y),ans1(z,y,x)));
    cout<<ans;
}

