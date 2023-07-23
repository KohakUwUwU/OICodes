#include<iostream>
using namespace std;
int main()
{
	int n,cnt=1;
	char last=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char tmp;
		cin>>tmp;
		if(tmp!=last)cnt++;
		last=tmp;
	}
	cout<<cnt;
}
