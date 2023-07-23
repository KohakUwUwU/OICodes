#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double a,b,c;
	double p;
	cin>>a>>b>>c;
	p=(a+b+c)/2.0;
	cout<<fixed<<setprecision(1)<<sqrt(p*(p-a)*(p-b)*(p-c));
}
