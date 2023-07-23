#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a,n;
	cin>>a>>n;
	cout<<fixed<<setprecision(3)<<a/n;
	cout<<endl<<(int(n)<<1);
}
