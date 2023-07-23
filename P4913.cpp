#include<iostream>
using namespace std;
int n,mxdep=-1,dep=1;
inline void build()
{
	mxdep=max(mxdep,dep);
	register int a,b;
	cin>>a>>b;
	if(a==0&&b==0)
	{
		mxdep=max(mxdep,dep);
		return ;
	}
	dep++;
	if(a!=0)build();
	if(b!=0)build();
	dep--;
}
int main()
{
	cin>>n;
	build();
	cout<<mxdep;
}
