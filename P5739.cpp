#include<iostream>
using namespace std;
int dfs(int kkksc03)
{
	if(kkksc03==1)return 1;
	return kkksc03*dfs(kkksc03-1);
}
int n;
int main()
{
	cin>>n;
	cout<<dfs(n);
}
