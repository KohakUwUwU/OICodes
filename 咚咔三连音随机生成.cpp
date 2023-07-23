//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	srand((int)time(0));
	for(int i=1;i<=100;i++)
	{
		for(int i=1;i<=3;i++)
		{
			int note=rand()%2;
			if(note)cout<<"o";
			else cout<<"x";
		}
		cout<<' ';
	}
	return 0;
}

