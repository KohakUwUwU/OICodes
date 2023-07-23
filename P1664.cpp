#include<iostream>
using namespace std;
int n;
int days[1086];
int cnt;
int l;
int marks;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>days[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(days[i]==1)
		{
			if(l!=0)
			{
				cnt-=1<<(l-1);
			}
			if(cnt<0)
			{
				cnt=0;
			}
			l=0;
			cnt++;
			marks++;
			if(cnt>=3)
			{
				marks++;
			}
			if(cnt>=7)
			{
				marks++;
			}
			if(cnt>=30)
			{
				marks++;
			}
			if(cnt>=120)
			{
				marks++;
			}
			if(cnt>=365)
			{
				marks++;
			}
		}else
		{
			l++;
		}
	}
	cout<<marks;
}
