#include<iostream>
using namespace std;
int n,a,b,c;
string name,ansname;
int ansa,ansb,ansc,anssum=-1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>name>>a>>b>>c;
		if(anssum<a+b+c)
		{
			anssum=a+b+c;
			ansa=a;ansb=b;ansc=c;
			ansname=name;
		}
	}
	cout<<ansname<<" "<<ansa<<" "<<ansb<<" "<<ansc;
}
