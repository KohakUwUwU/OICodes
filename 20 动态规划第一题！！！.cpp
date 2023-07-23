#include<iostream>
using namespace std;
int m,n,w[101],c[101],f[101];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i]>>c[i];
	for(int i=1;i<=n;i++)for(int j=m;j>=0;j--)if(j>=w[i])f[j]=max(f[j],f[j-w[i]]+c[i]);
	cout<<f[m];
}
