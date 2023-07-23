#include<iostream>
using namespace std;
int a[101]={};
bool prime(int n)
{
	if(n==1)return 0;
	for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}
int main()
{
	while(1)
	{
		int n,k,m=0,time=0;//k当前 m上一楼层数 
		cin>>n;
		if(n==0)return 0;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			time+=((m-k)>0?(m-k)*4:(k-m)*6+5);
			if(prime(time+k))a[k]=1;
			m=k; 
		}
		bool flag=true;
		for(int i=1;i<=100;i++)
		{
			if(a[i]==1){
				cout<<i<<" ";
				flag=false;
			}
		}
		if(flag==true)cout<<"No";
	}
}
