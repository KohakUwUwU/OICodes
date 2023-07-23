#include<iostream>
using namespace std;
int a[51][2];
int main()
{
	for(int i=1;i<=50;i++)
	{
		cin>>a[i][0]>>a[i][1];
		if(a[i][1]>=80)cout<<a[i][0]<<" "<<a[i][1]<<endl;
	}
}
