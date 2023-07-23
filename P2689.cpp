#include<iostream>
#include<cmath>
using namespace std;
int sx,sy,ex,ey,n;
int bin[128];
int main()
{
	cin>>sx>>sy>>ex>>ey;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		bin[c]++;
	}
	char x,y;
	if(sx<ex)x='E';
	else x='W';
	if(sx<ey)y='N';
	else y='S';
	if(bin[x]<abs(sx-ex)||bin[y]<abs(sy-ey))cout<<-1;
	else cout<<abs(sx-ex)+abs(sy-ey);
}
