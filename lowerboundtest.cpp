#include<iostream>
using namespace std;
int main()
{
	int a[] = {1,2,3};
	//´òÓ¡ 2 µÄÎ»ÖÃ
	cout << lower_bound(a, a + 3, 2) - a;
}
