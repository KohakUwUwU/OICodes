//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

double x[5],y[5];
signed main()
{
	for(int i=1;i<=4;i++)cin>>x[i]>>y[i];
	double k1=(y[1]-y[3])/(x[1]-x[3]);
	double k2=(y[2]-y[4])/(x[2]-x[4]);
	double X=(y[2]-y[1]+k1*x[1]-k2*x[2])/(k1-k2);
	if(x[1]<=X&&X<=x[3])cout<<"Yes";
	else cout<<"No";
	return 0;
}

