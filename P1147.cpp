//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n; 
signed main()
{
	cin>>n;
	int p1=1,p2=1,sum=1;
	while(sum<n)sum+=++p2;
	if(sum==n)cout<<p1<<' '<<p2<<'\n',sum+=++p2;
	for(;p2<n;sum+=++p2)
	{
		while(sum>n)sum-=p1++;
		if(sum==n)cout<<p1<<' '<<p2<<'\n';
	}
	return 0;
}

