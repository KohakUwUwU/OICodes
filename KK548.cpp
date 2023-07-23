//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

int n;
signed main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	set<int> s;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)s.insert(i);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		set<int>::iterator it=s.lower_bound(x);
		if(it==s.end())it--,s.erase(it);
		else if(*it==x)s.erase(it);
		else if(it==s.begin())ans++;
		else it--,s.erase(it);
	}
	printf("%lld",ans);
	return 0;
}

