#include<iostream>
using namespace std;
int cnt=0,l,r;
inline void judge(int k)
{
	if(k==0)return ;
	if(k%10==2)cnt++;
	judge(k/10);
}
int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		judge(i);
	}
	cout<<cnt;
}
