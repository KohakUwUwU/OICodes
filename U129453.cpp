#include<bits/stdc++.h>
#include<map>
#define ll long long
using namespace std;
ll k,n,sum=1;
map<int,ll>qj;
inline ll checker()
{
	for(int i=2;i<=qj[0];i++)
	{
		if((qj[i]-qj[i-1])/2-1>=k)return i;
	}
	return -1;
} 
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		cout<<n;
		return 0;
	}
	qj[++qj[0]]=1;qj[++qj[0]]=n+1;
	while(1)
	{
		ll c=checker();
		if(c==-1){
			cout<<sum;
			return 0;
		}
//		cout<<c<<" ";
		for(int i=qj[0];i>=c;i--)qj[i+1]=qj[i];
		qj[c]=(qj[c-1]+qj[c+1])/2;
//		cout<<qj[c]<<endl;
		qj[0]++;
		sum++;
	}
	printf("%lld",&sum);
}
