#include<iostream>
using namespace std;
bool kk(int n)
{
	for(int i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}
int sum=1;
int b[1000005];
int main()
{
	cout<<"2,";
	b[2]=1;
	for(int i=3;i<=1000000;i++)
	{
		if(kk(i))cout<<i<<",",sum++,b[i]=1;
	}
	cout<<endl<<endl<<sum<<endl<<endl;
	for(int i=1;i<=1000000;i++)cout<<b[i]<<",";
}
