#include<iostream>
using namespace std;
int main()
{
	int k,tmp=0;
	cin>>k;
	for(int i=10000;i<=30000;i++)
	{
		if(i/100%k==0&&i/10%1000%k==0&&i%1000%k==0)tmp=1,cout<<i<<endl;
	}
	if(tmp==0)cout<<"No";
}
