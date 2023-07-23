//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
int t,G[N][N];
inline bool check1(int i,int j)
{
	return (G[i+1][j]==1&&G[i][j+1]==1&&G[i+1][j+1]==1);
}
inline bool check2(int i,int j)
{
	return (G[i][j]==1&&G[i+1][j]==1&&G[i+1][j+1]==1);
}
inline bool check3(int i,int j)
{
	return (G[i][j]==1&&G[i][j+1]==1&&G[i+1][j+1]==1);
}
inline bool check4(int i,int j)
{
	return (G[i][j]==1&&G[i+1][j]==1&&G[i][j+1]==1);
}
inline bool pass1(int i,int j)
{
	return (G[i][j]==0&&G[i-1][j]==0&&G[i-1][j+1]==0&&G[i-1][j+2]==0&&G[i][j-1]==0&&G[i+1][j-1]==0&&G[i+2][j-1]==0&&G[i+2][j]==0&&G[i+2][j+1]==0&&G[i+2][j+2]==0&&G[i+1][j+2]==0&&G[i][j+2]==0);
}
inline bool pass2(int i,int j)
{
	return (G[i-1][j-1]==0&&G[i-1][j]==0&&G[i-1][j+1]==0&&G[i][j+1]==0&&G[i][j-1]==0&&G[i+1][j-1]==0&&G[i+2][j-1]==0&&G[i+2][j]==0&&G[i+2][j+1]==0&&G[i+2][j+2]==0&&G[i+1][j+2]==0&&G[i][j+2]==0);
}
inline bool pass3(int i,int j)
{
	return (G[i-1][j-1]==0&&G[i-1][j]==0&&G[i-1][j+1]==0&&G[i-1][j+2]==0&&G[i][j-1]==0&&G[i+1][j-1]==0&&G[i+1][j]==0&&G[i+2][j]==0&&G[i+2][j+1]==0&&G[i+2][j+2]==0&&G[i+1][j+2]==0&&G[i][j+2]==0);
}
inline bool pass4(int i,int j)
{
	return (G[i-1][j-1]==0&&G[i-1][j]==0&&G[i-1][j+1]==0&&G[i-1][j+2]==0&&G[i][j-1]==0&&G[i+1][j-1]==0&&G[i+2][j-1]==0&&G[i+2][j]==0&&G[i+2][j+1]==0&&G[i+1][j+1]==0&&G[i+1][j+2]==0&&G[i][j+2]==0);
}
inline bool p1(int i,int j)
{
	return check1(i,j)&&!pass1(i,j);
}
inline bool p2(int i,int j)
{
	return check2(i,j)&&!pass2(i,j);
}
inline bool p3(int i,int j)
{
	return check3(i,j)&&!pass3(i,j);
}
inline bool p4(int i,int j)
{
	return check4(i,j)&&!pass4(i,j);
}
signed main()
{
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(G,0,sizeof(G));
		for(int i=1;i<=n;i++)
		{
			string str;
			cin>>str;
			for(int j=0;j<m;j++)G[i][j+1]=(str[j]=='*'?1:0);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(G[i][j]=='.')continue;
				if(!(check1(i-1,j)||check1(i,j-1)||check1(i-1,j-1)||check2(i,j)||check2(i-1,j)||check2(i-1,j-1)||check3(i,j)||check3(i,j-1)||check3(i-1,j-1)||check4(i,j)||check4(i-1,j)||check4(i,j-1)))
				{
					cout<<"NO1\n";
					goto sbga;
				}
				int cnt=0;
				if(check1(i-1,j))cnt++;
				if(check1(i,j-1))cnt++;
				if(check1(i-1,j-1))cnt++;
				if(check2(i,j))cnt++;
				if(check2(i-1,j))cnt++;
				if(check2(i-1,j-1))cnt++;
				if(check3(i,j))cnt++;
				if(check3(i,j-1))cnt++;
				if(check3(i-1,j-1))cnt++;
				if(check4(i,j))cnt++;
				if(check4(i-1,j))cnt++;
				if(check4(i,j-1))cnt++;
				if(cnt>1)
				{
					cout<<"NO\n";
					goto sbga;
				}
				if(p1(i-1,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p1(i,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p1(i-1,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p2(i,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p2(i-1,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p2(i-1,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p3(i,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p3(i,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p3(i-1,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p4(i,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p4(i-1,j)){
					cout<<"NO\n";
					goto sbga;
				}
				if(p4(i,j-1)){
					cout<<"NO\n";
					goto sbga;
				}
			}
		}
		cout<<"YES\n";
		sbga:;
	}
	return 0;
}

