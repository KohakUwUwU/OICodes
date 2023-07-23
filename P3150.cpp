#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int tmp;
		cin>>tmp;
		if(tmp%2==0)cout<<"pb wins\n";
		else cout<<"zs wins\n";
	}
}
