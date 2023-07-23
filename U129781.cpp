#include<iostream>
#include<algorithm>
using namespace std;
int n,flag=0;
long long q[100001],sorbefore[100001],sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&sorbefore[i]),q[i]=sorbefore[i];
	sort(q+1,q+1+n);
	for(int i=1;i<=n;i++)cout<<q[i]<<" ";
	while(!q[++flag]);
	for(int i=flag;i<=n;i++)if(sorbefore[0]>sorbefore[i])sum++,sum%=1000000007,cout<<"yes";
	sum*=(flag-1);
	for(int i=flag;i<n;i++)for(int j=i+1;j<=n;j++)if(sorbefore[i]>sorbefore[j])sum++,sum%=1000000007;
	printf("%lld",sum);
}
