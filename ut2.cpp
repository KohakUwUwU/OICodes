#include<iostream>
#include<map>
using namespace std;
int n,m;
map<int,int>pri;
inline int gcd(int a,int b) {
	while(b^=a^=b^=a%=b);
    return a;
}
inline bool prime(int k)
{
	for(int i=2;i*i<=k;i++)if(k%i==0)return false;
	return true;
}
int main()
{
	cin>>n>>m;
	int tmp=gcd(n,m);
	prime(tmp);
	if(tmp==1){
		cout<<-1;
		return 0;
	}
	while(1)
	{
		if(prime(tmp)&&!(n%tmp)&&!(m%tmp))break;
		tmp--;
	}
	cout<<tmp;
}
