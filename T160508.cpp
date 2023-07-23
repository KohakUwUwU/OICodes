#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	long double n;
	cin>>n;
	if(n>=90.0)cout<<"4.0";
	else if(n>=60.0)cout<<fixed<<setprecision(1)<<4.0-(90-n)*0.1;
	else 
	{
		if(floor(sqrt(n)*10.0)>=60.0)cout<<fixed<<setprecision(1)<<4.0-(90-floor(sqrt(n)*10.0))*0.1;
		else cout<<"0.0";
	}
}
