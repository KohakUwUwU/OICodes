//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	for(int i=1;i<=10;i++)
	{
		system("KK1147GEN.exe");
		cout<<"Complete T="<<i<<" gen\n";
		system("KK1147SOLVE.exe");
		cout<<"Complete T="<<i<<" SOLVE\n";
		system("KK1147BF.exe");
		cout<<"Complete T="<<i<<" BF\n";
		system("fc xjjSOLVE.out xjjBF.out");
	}
	return 0;
}

