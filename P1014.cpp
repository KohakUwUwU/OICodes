#include<iostream>
using namespace std;
int n,i=0,j=0;
int main()
{
	cin>>n;
	while(j<n)j+=++i;
	if(i%2==1)cout<<j-n+1<<"/"<<i-j+n;
	else cout<<i-j+n<<"/"<<j-n+1;
}
