#include<bits/stdc++.h>
#define N (int)1e5+1
using namespace std;
double a[N],x1[N],x2[N],ans[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],x1[i]=x1[i-1]*a[i]+a[i],x2[i]=(x2[i-1]+(x1[i-1]*2)+1)*a[i],ans[i]=ans[i-1]+(3*(x1[i-1]+x2[i-1])+1)*a[i];
	cout<<fixed<<setprecision(1)<<ans[n];
}
