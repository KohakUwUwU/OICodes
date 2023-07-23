#include<bits/stdc++.h>
using namespace std; 

void dfs(int x)
{
	if(x==0) return;
	int t=x;
	x=t;
	dfs(x-1);
}

int main()
{
	dfs(1000000);
	return 0;
}
