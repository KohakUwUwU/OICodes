#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, res = 0;
	cin >> n;
	if (n % 2 == 0)res++;
	if (n > 4 && n <= 12)res++;
	cout <<( res == 2 ? 1 : 0 )<< " " <<( res > 0 ? 1 : 0 )<< " " <<( res == 1 ? 1 : 0 )<< " " <<( res == 0 ? 1 : 0);
}

