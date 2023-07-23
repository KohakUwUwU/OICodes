//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

int clr[5][5];
int ans[5];
signed main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		for(int i=1;i<=4;i++)ans[i]=114514114514;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=4;j++)
			{
				cin>>clr[i][j];
				ans[j]=min(ans[j],clr[i][j]);
			}
		}
		int ret=0;
		for(int i=1;i<=4;i++)ret+=ans[i];
		int output=1000000;
		if(ret>=1000000)
		{
			for(int i=1;i<=4;i++)
			{
				if(output>=ans[i])cout<<ans[i]<<' ',output-=ans[i];
				else cout<<output<<' ',output=0;
			}
		}
		else
		{
			cout<<"IMPOSSIBLE";
		}
		cout<<'\n';
	}
	return 0;
}

