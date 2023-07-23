//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	freopen("dorm3.in","w",stdout);
	srand(time(0));
	int n=rand()%2000+1;
	printf("%lld\n",n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)printf("%d ",rand()%2000+1);
		printf("\n");
	}
	return 0;
}

