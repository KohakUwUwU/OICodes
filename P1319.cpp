#include<iostream>
using namespace std;
int n,type=0;
int main()
{
	cin>>n;
	int tmp,i=1;
	while(scanf("%d",&tmp))
	{
		for(int j=1;j<=tmp;j++,i++)
		{
			cout<<type;
			if(i%n==0)cout<<endl;
		}
		type=(type==1?0:1);
		if(i>=n*n)return 0;
	}
}
