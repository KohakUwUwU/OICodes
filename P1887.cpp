#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int i=1;
	for(i=1;i<=n-(m%n);i++) cout<<m/n<<" ";
	for(i=1;i<=m%n;i++) cout<<m/n+1<<" ";
	return 0;
}
