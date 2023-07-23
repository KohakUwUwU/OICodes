#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double a[4][3];
	int b[4];
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		cin>>a[i][1]>>a[i][2];
		b[i]=ceil(n/a[i][1]);
	}
	cout<<int(min(min(b[1]*a[1][2],b[2]*a[2][2]),b[3]*a[3][2]));
}
