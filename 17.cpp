#include<iostream>
using namespace std;
int main()
{
	char c1,c2;
	int i1,i2;
	cin>>c1>>i1>>c2>>i2;
	if(c1==c2)cout<<"especially";
	else if(i1==i2)cout<<"legendary";
	else cout<<"ordinary";
}
