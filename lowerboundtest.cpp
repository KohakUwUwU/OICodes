#include<iostream>
using namespace std;
int main()
{
	int a[] = {1,2,3};
	//��ӡ 2 ��λ��
	cout << lower_bound(a, a + 3, 2) - a;
}
