#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int cnt=0;
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		a*=c;d*=c;
		for(long long i=1;i*b<d;i++)
		{
			if(a%((d-i*b)/__gcd(d-i*b,i))<=0)++cnt;
		}
		cout<<cnt<<endl;
	}
}
