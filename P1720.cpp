#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<fixed<<setprecision(2)<<(pow((1.0+sqrt(5))/2.0,n)-pow((1.0-sqrt(5))/2.0,n))/sqrt(5);
}
