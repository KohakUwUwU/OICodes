#include<iostream>
using namespace std;
int n;
string s[1003];
bool f[1003];
signed main()
{
	cin>>n;
	string a,b,c;
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		if(a[0]=='t') 
		{
			cin>>s[i];
			f[i]=1;
			for(int j=1; j<i; j++) if(f[j]==1&&s[j]==s[i]) f[i]=0;
		}
		else if(a[1]=='m') 
		{
			cin>>b;
			for(int j=1; j<i; j++) if(b==s[j]) f[j]=0; 
			f[i]=0;
		}
		else if(a[1]=='e')
		{
			cin>>b>>c;
			if(b==c) continue;
			int pos=-1;bool ff=1;
			for(int j=1; j<i&&ff; j++) if(b==s[j]) pos=j,ff&=f[j];
			 else if(c==s[j]) ff=0;
			if(ff==0||pos==-1) continue; 
			s[pos]=c;f[i]=0;
		 } 
		else 
		{
			for(int j=1; j<i; j++) if(f[j]) cout<<s[j]<<endl;
			f[i]=0;
		}
	}
}

