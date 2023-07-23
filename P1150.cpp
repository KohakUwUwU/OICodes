#include<iostream>
using namespace std;
int main()
{
	int n,k,cur,tra=0,cnt=0;
	cin>>n>>k;
	cur=n;
	while(cur>0)
	{
		cnt++;
		cur--;
		tra++;
		if(tra==k)cur++,tra=0;
	}
	cout<<cnt;
}
