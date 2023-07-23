#include<bits/stdc++.h>
using namespace std;
int n,k,f[100005]={1,1};
int main()
{
	cin>>n>>k;
	for(int i=2;i<=n;i++)for(int j=1;j<=k;j++)if(i>=j)f[i]=(f[i]+f[i-j])%100003;
	cout<<f[n];
}
