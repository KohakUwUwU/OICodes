#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		string str;
		cin>>str;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			bool aif=false,bif=false;
			for(int i=0;i<str.length();i++)
			{
				if(str[i]==str[a]&&i<a)aif=true;
				if(str[i]==str[b]&&i>b)bif=true;
			}
			if(!aif&&!bif)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
}
