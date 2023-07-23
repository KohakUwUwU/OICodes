//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	freopen("xjj.in","w",stdout);
	srand((int)time(0));
	int n=rand()%10;
	int k=rand()%n+1;
	printf("%lld %lld\n",n,k);
	for(int i=1;i<=n;i++)printf("%lld ",(long long)(rand()%1000+10005));
	return 0;
}

