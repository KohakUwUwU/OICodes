#include<bits/stdc++.h>
using namespace std;
int m,n,kkksc03[101][101],maxans=-1;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		int sum=0,maxx=-1,minn=0x3f3f3f3f,input;
		for(int j=1;j<=n;j++)
		{
			cin>>input;
			maxx=max(maxx,input);
			minn=min(minn,input);
			sum+=input;
		}
		maxans=max(maxans,sum-minn-maxx);
	}
	cout<<fixed<<setprecision(2)<<maxans*1.0/((n-2)*1.0);
}
