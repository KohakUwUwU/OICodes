#include<iostream>
using namespace std;
int main()
{
	int a[9][9]={};
	for(int i=1;i<=8;i++){
		a[1][i]=1;
		a[i][1]=1;
	}
	for(int i=2;i<=8;i++)
	{
		for(int j=2;j<=8;j++)
		{
			a[i][j]=a[i][j-1]+a[i-1][j];
		}
	}
	cout<<a[8][8];
}
