//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[5][5];
signed main()
{
	for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)cin>>a[i][j];
	int b=0;
	if(a[1][4]&&(a[1][1]||a[1][2]||a[1][3]||a[2][1]||a[3][2]||a[4][3]))b=1;
	if(a[2][4]&&(a[2][1]||a[2][2]||a[2][3]||a[3][1]||a[4][2]||a[1][3]))b=1;
	if(a[3][4]&&(a[3][1]||a[3][2]||a[3][3]||a[4][1]||a[1][2]||a[2][3]))b=1;
	if(a[4][4]&&(a[4][1]||a[4][2]||a[4][3]||a[1][1]||a[2][2]||a[3][3]))b=1;
	if(b)cout<<"YES";
	else cout<<"NO";
	return 0;
}

