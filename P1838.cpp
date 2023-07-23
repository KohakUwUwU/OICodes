#include<iostream>
#include<cstring>
using namespace std;
int map[4][4];
string str[2]={"xiaoa wins.","uim wins."};
int main()
{
	memset(map,-1,sizeof(map));
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)a[i]-='0',map[(a[i]-1)/3][(a[i]-1)%3]=i%2;
	for(int i=0;i<3;i++)
	{
		if(map[i][0]==map[i][1]&&map[i][0]==map[i][2]&&map[i][0]!=-1)
		{
			cout<<str[map[i][0]];
			return 0;
		}
		if(map[0][i]==map[1][i]&&map[0][i]==map[2][i]&&map[0][i]!=-1)
		{
			cout<<str[map[0][i]];
			return 0;
		}
	}
	if((map[0][0]==map[1][1]&&map[1][1]==map[2][2]||map[2][0]==map[1][1]&&map[1][1]==map[0][2])&&map[1][1]!=-1)cout<<str[map[1][1]];
	else cout<<"drew.";
}
