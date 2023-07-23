//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505;
int h,w,G[N][N],vis[N][N];
signed main()
{
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<str.length();j++)
		{
			if(str[j]=='U')G[i][j+1]=1;
			if(str[j]=='D')G[i][j+1]=2;
			if(str[j]=='L')G[i][j+1]=3;
			if(str[j]=='R')G[i][j+1]=4;
		}
	}
	int curx=1,cury=1;
	while(!vis[curx][cury])
	{
		vis[curx][cury]=1;
		if(G[curx][cury]==1)
		{
			if(curx==1)
			{
				cout<<curx<<' '<<cury;
				return 0;
			}
			curx--;
		}
		if(G[curx][cury]==2)
		{
			if(curx==h)
			{
				cout<<curx<<' '<<cury;
				return 0;
			}
			curx++;
		}
		if(G[curx][cury]==3)
		{
			if(cury==1)
			{
				cout<<curx<<' '<<cury;
				return 0;
			}
			cury--;
		}
		if(G[curx][cury]==4)
		{
			if(cury==w)
			{
				cout<<curx<<' '<<cury;
				return 0;
			}
			cury++;
		}
	}
	cout<<-1;
	return 0;
}

