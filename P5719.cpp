#include<bits/stdc++.h>
using namespace std;
int n,k,cnt1,cnt2;
double st1,st2;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		if(i%k==0)st1+=i,cnt1++;
		else st2+=i,cnt2++;
	}
	cout<<fixed<<setprecision(1)<<st1/double(cnt1)<<' '<<st2/double(cnt2);
}
