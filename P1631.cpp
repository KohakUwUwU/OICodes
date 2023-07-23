#include<map>
#include<iostream>
using namespace std;
long long line1[1000001],line2[1000001],n,Max=-1;
map<int,int>bin;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>line1[i];
	for(int i=1;i<=n;i++)cin>>line2[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)Max=max(Max,line1[i]+line2[j]),bin[line1[i]+line2[j]]=1;
	for(int i=1;i<=Max&&n;i++)if(bin[i]==1)cout<<i<<" ",n--;
}
