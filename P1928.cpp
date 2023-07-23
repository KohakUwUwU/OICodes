#include<iostream>
using namespace std;
string str;
int main()
{
	cin>>str;
	int m=str.length();
	int mul=1;
	for(int i=0;i<m;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			int tmp=str[i]-'0';
			while(str[++i]>='0'&&str[i]<='9'&&i<m)tmp=tmp*10+str[i]-'0';
			mul*=tmp;
			i--;
		}
		else if(str[i]!='['&&str[i]!=']')
		{
			string temp;
			temp+=str[i];
			while((str[++i]<'0'||str[i]>'9')&&str[i]!='['&&str[i]!=']'&&i<m)temp+=str[i];
			for(int i=1;i<=mul;i++)cout<<temp;
			mul=1;
		}
	}
}
