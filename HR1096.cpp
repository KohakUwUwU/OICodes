#include<iostream>
using namespace std;
string str;
int main()
{
	for(int i=1;i<=3;i++)
	{
		int l=0,n=0,s=0,o=0;
		getline(cin,str);
		for(int j=0;j<str.length();j++)
		{
			if(str[j]>='A'&&str[j]<='Z'||str[j]>='a'&&str[j]<='z')l++;
			else if(str[j]>='0'&&str[j]<='9')n++;
			else if(str[j]==' ')s++;
			else o++;
		}
		printf("%d %d %d %d\n",l,n,s,o);
	}
}
