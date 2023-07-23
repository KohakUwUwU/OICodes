#include<iostream>
using namespace std;
int n;
struct node
{
	int x,y;
}data[10001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>data[i].x>>data[i].y;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double k=1.0*(data[i].y*1.0-data[j].y*1.0)/(data[i].x*1.0-data[j].x*1.0);
			if()
		}
	}
}
