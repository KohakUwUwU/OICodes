//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=45;
int t;
char arr[N];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		int len;
		string str;
		scanf("%lld",&len);
		cin>>str;
		for(int i=0;i<len;i++)arr[i]=str[i];
		sort(arr,arr+len);
		int cnt=0;
		for(int i=0;i<len;i++)if(arr[i]==str[i])cnt++;
		cout<<len-cnt<<'\n';
	}
	return 0;
}

