#include<iostream>
using namespace std;
int n,m;
char dir;
char ma[101][101];
int main()
{
	cin>>n>>m>>dir;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<str.length();j++)
		{
			ma[i][j]=str[j];
		}
	}
	if(dir=='v')
	{
		for(int i=0;i<m;i++)
		{
			bool d=false;
			for(int j=0;j<n;j++)
			{
				if(ma[j][i]=='o')d=true;
				if(ma[j][i]=='x'&&d==true)
				{
					cout<<"GG";
					return 0;
				}
			}
		}
	}if(dir=='^')
	{
		for(int i=0;i<m;i++)
		{
			bool d=false;
			for(int j=n-1;j>=0;j--)
			{
				if(ma[j][i]=='o')d=true;
				if(ma[j][i]=='x'&&d==true)
				{
					cout<<"GG";
					return 0;
				}
			}
		}
	}if(dir=='>')
	{
		for(int i=0;i<n;i++)
		{
			bool d=false;
			for(int j=0;j<m;j++)
			{
				if(ma[i][j]=='o')d=true;
				if(ma[i][j]=='x'&&d==true)
				{
					cout<<"GG";
					return 0;
				}
			}
		}
	}if(dir=='v')
	{
		for(int i=0;i<n;i++)
		{
			bool d=false;
			for(int j=m-1;j>=0;j--)
			{
				if(ma[i][j]=='o')d=true;
				if(ma[i][j]=='x'&&d==true)
				{
					cout<<"GG";
					return 0;
				}
			}
		}
	}
	cout<<"OK";
}
