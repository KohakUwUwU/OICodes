#include<bits/stdc++.h>
using namespace std;
map<string,int>a;
map<int,int>s,c,ds;
int m,n,ans;
string x[101];
int main()
{
	cin>>m>>n;
	int rest=21-m,wn=n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>c[i]>>ds[i];
		if(s[i]>ds[i])s[i]=ds[i];
		cin>>x[i];
		if(a[x[i]]>0)
		{
			wn--;
			s[a[x[i]]]+=s[i];
			if(s[a[x[i]]]>ds[i])s[a[x[i]]]=ds[i];
		}
		else a[x[i]]=i;
	}
	while(rest>0)
	{
		int maxn=0,maxr=0;
		for(int i=1;i<=wn;i++)
		{
			if(a[x[i]]>0)
			{
				if(s[i]*c[i]>maxn)
				{
					maxn=s[i]*c[i];
					maxr=i;
				}
			}
		}
		ans+=maxn;
		a[x[maxr]]=0;
		rest--;
	}
	cout<<ans;
}
