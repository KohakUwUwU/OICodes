//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
1 2 3
+2-3
3 -1 3
3 1 0
0 1 2
ÿ��һ��������Сֵ����ִ�У���Ȼһ���������� 
*/
signed main()
{
	int n;
	cin>>n;
	cout<<2*n<<'\n';
	int a=n%4,b=n/4;
	if(a)cout<<a;
	for(int i=1;i<=b;i++)cout<<4;
	return 0;
}

