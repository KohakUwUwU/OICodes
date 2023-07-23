#include<iostream>
using namespace std;
int t,bin[40];
int re[10];
int main()
{
	cin>>t;
	for(int i=1;i<=7;i++)
	{
		register int tmp;
		cin>>tmp;
		bin[tmp]=1;
	}
	while(t--)
	{
		int cnt=0;
		for(int i=1;i<=7;i++)
		{
			register int tmp;
			cin>>tmp;
			if(bin[tmp]==1)cnt++;
		}
		re[cnt]++;
	}
	for(int i=7;i>=1;i--)cout<<re[i]<<" ";
}
