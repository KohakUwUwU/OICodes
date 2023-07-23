//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

int mmm[15]={0,31,0,31,30,31,30,31,31,30,31,30,31};
inline bool run(int yy)
{
	if(yy%4==0&&yy%100!=0||yy%400==0)return true;
	return false;
}
inline void Calc(int yy,int mm,int dd)
{
	int y=1971;
	int wji=4;
	while(y<yy)
	{
		if(run(y))wji=(wji+366)%7;
		else wji=(wji+365)%7;
		y++;
	}
	int m=1;
	while(m<mm)
	{
		if(m==2)
		{
			if(run(yy))wji=(wji+29)%7;
			else wji=(wji+28)%7;
		}
		else wji=(wji+mmm[m])%7;
		m++;
	}
	wji=(wji+dd-1)%7;
	switch(wji)
	{
		case 0:
			cout<<"Monday";
			break;
		case 1:
			cout<<"Tuesday";
			break;
		case 2:
			cout<<"Wednesday";
			break;
		case 3:
			cout<<"Thursday";
			break;
		case 4:
			cout<<"Friday";
			break;
		case 5:
			cout<<"Saturday";
			break;
		case 6:
			cout<<"Sunday";
			break;
	}
}
signed main()
{
	freopen("week.in","r",stdin);
	freopen("week.out","w",stdout);
	int yy,mm,dd;
	cin>>yy>>mm>>dd;
	Calc(yy,mm,dd);	
	return 0;
}

