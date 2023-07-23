#include<iostream>
using namespace std;
int calc(int k)
{
	if(k==2)return 1;
	else if(k==1)return 0;
	else return (k-1)*(calc(k-1)+calc(k-2));
}
int main()
{
	int n;
	cin>>n;
	cout<<calc(n);
}
