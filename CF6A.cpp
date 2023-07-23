//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	int a[5];
	for(int i=1;i<=4;i++)cin>>a[i];
	sort(a+1,a+5);
	if(a[1]+a[2]>a[3]||a[2]+a[3]>a[4])cout<<"TRIANGLE";
	else if(a[1]+a[2]==a[3]||a[2]+a[3]==a[4])cout<<"SEGMENT";
	else cout<<"IMPOSSIBLE";
	return 0;
}

