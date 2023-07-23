#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("mode.in","w",stdout);
	srand(time(0));
	int n=rand()%1000+1000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		int opt=rand()%2+1;
		int val=rand()%1000+10000;
		printf("%d %d\n",opt,val);
	}
	return 0;
}
