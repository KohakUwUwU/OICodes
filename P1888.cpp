#include<iostream>
#include<algorithm>
using namespace std;
inline long long gcd(long long a,long long b) {
    while(b^=a^=b^=a%=b);
    return a;
}
int a[3];
int main()
{
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<a[0]/gcd(a[0],a[2])<<"/"<<a[2]/gcd(a[0],a[2]);
}
