//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int col[10];
signed main()
{
	string str;
	cin>>str;
	if(str[0]=='1') 
	{
		cout<<"No";
		return 0;
	}
	col[1]=str[6]-'0';
	col[2]=str[3]-'0';
	col[3]=str[7]+str[1]-2*'0';
	col[4]=str[0]+str[4]-2*'0';
	col[5]=str[8]+str[2]-2*'0';
	col[6]=str[5]-'0';
	col[7]=str[9]-'0';
//	for(int i=1;i<=7;i++)cout<<col[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=6;i++)
	{
		for(int j=i+1;j<=7;j++)
		{
			if(col[i]==0||col[j]==0)continue;
			bool type=false;
			for(int k=i+1;k<j;k++)if(col[k]==0)type=true;
			if(type==true)
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}

