//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
int n,ans;
int a[N],b[N],bin[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int l1=1,l2=1,r1=n,r2=n;
	for(int i=1;i<=n;i++)
	{
		if(a[r1]>b[r2])ans+=200,r1--,r2--;
		else if(a[r1]<b[r2])ans-=200,l1++,r2--;
		else if(a[l1]>b[l2])ans+=200,l1++,l2++;
		else
		{
			if(a[l1]<b[r2])ans-=200;
			l1++,r2--;
		}
	}
	cout<<ans;
	return 0;
}

