#include <iostream>
#define R register
using namespace std;

int main()
{
	R int x, n;
	cin >> x >> n;
	R int d = n / 7 * 5; 
	R int r = n % 7;
	if (r > 0) 
	{
		if (r + x == 7 || x == 7)
			r -= 1;
		else if (r + x >= 8)
			r -= 2;
	}
	cout << (d + r) * 250 << endl;
	return 0;
}
