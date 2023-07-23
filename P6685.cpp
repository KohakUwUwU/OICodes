#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i=1;
	cin>>n>>m;
	while(pow(++i,m)<=n);
	cout<<i-1;
}
