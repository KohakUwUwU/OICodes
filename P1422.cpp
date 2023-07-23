#include<iostream>
#include<iomanip>
using namespace std;
double n,sum;
int main()
{
	cin>>n;
	if(n>=0)
	{
		sum+=n*0.4463;
	}
	if(n>=150)
	{
		sum+=(n-150)*0.02;
	}
	if(n>400)
	{
		sum+=(n-400)*0.1;
	}
	cout<<fixed<<setprecision(1)<<sum;
}
