#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
int n,ans,a[N];
string str;
signed main()
{
	cin>>n>>str;
	for(int i=0;i<str.length();i++)a[i+1]=(str[i]=='H');
	for(int i=1;i<=n;i++)a[i]=a[i-1]+a[i];
	for(int i=1;i<=n-2;i++)
	{
		int k=i,k1=i,val=a[i]-a[i-1];
		for(int j=30;j>=0;j--)
		{
			if(k+(1<<j)>n)continue;
			int p=a[k+(1<<j)]-a[i-1];
			if(p<=1||(k+(1<<j)-i+1-p)<=1)k+=(1<<j);
		}
		for(int j=30;j>=0;j--)
		{
			if(k1+(1<<j)>n)continue;
			if(val*(k1+(1<<j)-i+1)==a[k1+(1<<j)]-a[i-1])k1+=(1<<j);
		}
		ans+=k-max(k1,i+1);
	}
	cout<<ans;
	return 0;
}
