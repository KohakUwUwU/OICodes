//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	cout<<1<<','<<1<<',';
	int a=1,b=1;
	for(int i=1;i<=86;i++)
	{
		int temp=a+b;
		cout<<temp<<',';
		b=temp;
		swap(a,b);
	}
	return 0;
}

