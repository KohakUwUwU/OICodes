#include<iostream>
using namespace std;
int bin[43];
int main()
{
	int cnt=0;
	for(int tmp,i=0;i<10;i++)cin>>tmp,bin[tmp%42]++;
	for(int i=0;i<42;i++)if(bin[i])cnt++;
	cout<<cnt;
}
