#include<iostream>
using namespace std;
int tmp,sum;
int main()
{
	for(int i=1;i<=7;i++)cin>>tmp,sum+=tmp;
	cin>>tmp;if(tmp==1)sum+=5;
	cin>>tmp;if(tmp>sum+50)cout<<"AFO";
	else cout<<"AKIOI";
}
