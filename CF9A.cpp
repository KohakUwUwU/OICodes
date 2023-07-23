//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	int a,b,c;
	cin>>a>>b;
	c=max(a,b);
	c=6-c+1;
	if(c==0)cout<<"0/1";
	else if(c==1)cout<<"1/6";
	else if(c==2)cout<<"1/3";
	else if(c==3)cout<<"1/2";
	else if(c==4)cout<<"2/3";
	else if(c==5)cout<<"5/6";
	else cout<<"1/1";
	return 0;
}

