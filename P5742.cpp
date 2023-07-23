#include<iostream>
using namespace std;
int main()
{
	register int n,a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(b+c>140&&0.7*b+0.3*(c*1.0)>=80)cout<<"Excellent"<<endl;
		else cout<<"Not excellent"<<endl; 
	}
}
