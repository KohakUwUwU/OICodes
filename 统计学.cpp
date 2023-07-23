#include<iostream>
#include<algorithm>
using namespace std;
int n;
double a[1001];
double sum,x_ba,s2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	x_ba=sum/n;
	for(int i=1;i<=n;i++)s2+=(x_ba-a[i])*(x_ba-a[i]);
	s2/=n;
	cout<<"x_ba="<<x_ba<<'\n';
	cout<<"s^2="<<s2<<'\n';
	sort(a+1,a+1+n);
	if(n%2==0)cout<<"middle="<<(a[n/2]+a[n/2+2])/2;
	else cout<<"middle="<<a[n/2+1];
}
