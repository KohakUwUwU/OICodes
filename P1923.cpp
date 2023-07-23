#include<iostream>
#include<algorithm>
using namespace std;
int G[10000000];
int main()
{
	#define int register int
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%d",&G[i]);
	nth_element(G,G+m,G+n);
	cout<<G[m];
}
