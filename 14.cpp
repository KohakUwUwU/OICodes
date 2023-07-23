#include<iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	int n,sum=0,time=0,k[30][2]={};
	cin>>n;
	n-=4;
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(a[i]+a[j]+a[i+j]==n&&i+j<10){
				sum++;
				k[time][0]=i;k[time++][1]=j;
			}
		}
	}
	cout<<sum<<endl;
	for(int i=0;i<time;i++)
	{
		cout<<k[i][0]<<"+"<<k[i][1]<<"="<<k[i][0]+k[i][1]<<endl;
	}
}
