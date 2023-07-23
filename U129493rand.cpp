#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int m,n,map[2001][2001],sum;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&map[i][j]),sum+=map[i][j];
	srand((int)time(0));
	cout<<rand()%sum;
}
