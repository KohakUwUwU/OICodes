#include<iostream>
using namespace std;
int main()
{
	double n,m;
	cin>>n>>m;
	double k=n/m/m;
	if(k<18.5)cout<<"Underweight";
	else if(k<24)cout<<"Normal";
	else cout<<k<<endl<<"Overweight";
}
