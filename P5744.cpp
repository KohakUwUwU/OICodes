#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string a;
		register int b,c;
		cin>>a>>b>>c;
		cout<<a<<" "<<b+1<<" "<<(c*1.2<=600?c*1.2:600)<<endl;
	}
}
