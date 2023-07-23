//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=105;
int a[N],sum=0;
signed main()
{
	int t;
	cin>>t;
	while(t --> 0)
	{
		sum=0;
		int n,judge=0,b=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]),sum+=a[i];
			judge+=(i-1);
			if(sum<judge)
			{
				b=1;
			}
		}
		if(b)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}

