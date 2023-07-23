#include<iostream>
using namespace std;
int num[101],bin[200001],bo[200001],n,cnt;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i],bo[num[i]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			bin[num[i]+num[j]]++;
		}
	}
	for(int i=1;i<=200000;i++)cnt+=((bin[i]&&bo[i])?1:0);
	cout<<cnt;
}
