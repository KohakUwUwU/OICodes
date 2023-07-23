#include<iostream>
using namespace std;
int a,b,c;
int st[100],mx=-1,flag;
int main()
{
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)for(int k=1;k<=c;k++)st[i+j+k]++;
	for(int i=1;i<=a+b+c;i++)if(mx<st[i])mx=st[i],flag=i;
	cout<<flag;
}
