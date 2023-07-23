#include<iostream>
using namespace std;
int D,P,C,F,map[301][301],flight[301][301];
int main()
{
	cin>>D>>P>>C>>F;
	for(int i=1;i<=P;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	for(int i=1;i<=F;i++)
	{
		int a,b,cost;
		cin>>a>>b>>cost;
		flight[a][b]=cost;
	}
	
}
