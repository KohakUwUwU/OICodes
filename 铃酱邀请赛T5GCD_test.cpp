#include<iostream>
#include<cmath>
using namespace std;
inline long long gcd(long long a,long long b,long long c) {
    while(b^=a^=b^=a%=b);
    while(c^=a^=c^=a%=c);
    return a;
}
//inline long long gcd(long long a,long long b) {
//    while(b^=a^=b^=a%=b);
//    return a;
//}
//inline int gcd(int a,int b) 
//{
//    if(!a) return b;
//    if(!b) return a;
//    if(!(a | 1) && !(b | 1)) return gcd(a >> 1, b >> 1) << 1;
//    else if(!(a | 1)) return gcd(a >> 1, b);
//    else if(!(b | 1)) return gcd(a, b >> 1);
//    return gcd(abs(a - b), min(a, b));
//}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<gcd(a,b,c);
}
