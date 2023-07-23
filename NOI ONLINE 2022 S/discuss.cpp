//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+1;
int T,n;
bitset<N>bin[N];
signed main()
{
	freopen("discuss.in","r",stdin);
	freopen("discuss.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int tmp;
				cin>>tmp;
				bin[i][tmp]=true;
			}
		}
//		for(int i=1;i<=n;i++)cout<<bin[i].to_string()<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				bitset<N>c=bin[i]^bin[j];
				if(!((c&bin[i]).none()||(c&bin[j]).none())&&!(bin[i]&bin[j]).none())
				{
					cout<<"YES\n";
//					cout<<(bin[i]&bin[j]).to_ulong()<<'\n';
					cout<<i<<' '<<j<<'\n';
					goto ff;
				}
			}
		}
		cout<<"NO\n";
		ff:;
	}
	return 0;
}

