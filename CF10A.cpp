//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	int n,p1,p2,p3,t1,t2,s,ans=0;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1,l,r;i<=n;i++)
	{
		cin>>l>>r;
		if(i>1)
		{
			ans=ans+min(t1,l-s)*p1;
			if(l-s>t1)
			{
				ans=ans+min(l-s-t1,t2)*p2;
				if(l-s>t1+t2)
				{
					ans=ans+(l-s-t1-t2)*p3;
				}
			}
		}
		ans=ans+(r-l)*p1;
		s=r;
	}
	cout<<ans;
	return 0;
}

