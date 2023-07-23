#include<bits/stdc++.h>
#define dist(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;
struct node
{
	long double x,y;
}box[2001],track[2001];
int n,m;
long double r;
int main()
{
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)cin>>box[i].x>>box[i].y;
	for(int i=1;i<=m;i++)cin>>track[i].x>>track[i].y;
	for(int i=1;i<=n;i++)
	{
		if(dist(box[i].x,box[i].y,track[1].x,track[1].y)<=r)
		{
			int shabi=0;
			for(int j=2;j<=m;j++)
			{
				if(dist(box[i].x,box[i].y,track[j].x,track[j].y)>=r)
				{
					shabi=1;
					break;
				}
			}
			if(!shabi)cout<<i<<' ';
		}
	}
}
