#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	#define a arr[0]
	#define b arr[1]
	#define c arr[2]
	if(a+b<=c)
	{
		cout<<"Not triangle"<<endl;
		return 0;
	}
	if(a*a+b*b==c*c)cout<<"Right triangle"<<endl;
	if(a*a+b*b>c*c)cout<<"Acute triangle"<<endl;
	if(a*a+b*b<c*c)cout<<"Obtuse triangle"<<endl;
	if(a==b||a==c||b==c)cout<<"Isosceles triangle"<<endl;
	if(a==b&&a==c)cout<<"Equilateral triangle"<<endl;
}
