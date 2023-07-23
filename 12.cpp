#include<iostream>
using namespace std;
int main()
{
	int tmp=0;
	string a;
	cin>>a;
	if(a[0]=='-')
	{
		cout<<'-';
		for(int i=a.length()-1;i>0;i--)
		{
			if(tmp!=0||a[i]!=0)cout<<a[i],tmp++;
		}
	}
	else for(int i=a.length()-1;i>=0;i--)if(!(tmp==0||a[i]==0))cout<<a[i],tmp++;
}
