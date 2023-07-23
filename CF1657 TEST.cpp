//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dx[100];
int dy[100];
int cnt;
signed main()
{
	while(1)
	{
		int x,y;
		cin>>x>>y;
		if(x==0)break;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				++cnt;
				if(i==0)dx[cnt]=x;
				else dx[cnt]=-x;
				if(j==0)dy[cnt]=y;
				else dy[cnt]=-y;
			}
		}
		swap(x,y);
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				++cnt;
				if(i==0)dx[cnt]=x;
				else dx[cnt]=-x;
				if(j==0)dy[cnt]=y;
				else dy[cnt]=-y;
			}
		}
	}
	cout<<"int dx["<<cnt<<"]={";
	for(int i=1;i<cnt;i++)cout<<dx[i]<<',';
	cout<<dx[cnt]<<"};\n";
	cout<<"int dy["<<cnt<<"]={";
	for(int i=1;i<cnt;i++)cout<<dy[i]<<',';
	cout<<dy[cnt]<<"};\n";
}
