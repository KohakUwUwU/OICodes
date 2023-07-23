#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m,t,s;
	cin>>m>>t>>s;
	if(t*m<=s)
	{
		cout<<0;
		return 0;
	}
	cout<<int(double(m*t-s)/(double)t);
}
