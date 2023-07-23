#include<iostream>
using namespace std;
int n,m,r,st[101][2];
inline int dis(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	int cnt=0;
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++)cin>>st[i][0]>>st[i][1];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)
	{
		if(r*r>=dis(i,j,st[k][0],st[k][1]))
		{
			cnt++;
			break;
		}
	}
	cout<<cnt;
}
