#include<iostream>
#define R register
using namespace std;
int main()
{
	R int n;
	cin>>n;
	if(n%2==1)
	{
		cout<<-1;
		return 0;
	}
	R int cn=1,cnt=0,arr[100]={};
	while(n>0)
	{
		if(n%2==1)arr[++cnt]=cn;
		cn<<=1;
		n>>=1;
	}
	for(int i=cnt;i>=1;i--)cout<<arr[i]<<" ";
	return 0;
}
