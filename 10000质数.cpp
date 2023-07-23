
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
 
int a[30]; // 用于存放100以内的质数
int j = 5;
int line = 0;
 
// 先求出100以内的质数，输出并存储。
void solve100()
{
	for (int i = 11; i < 100; i++) {
		if (i % a[2] && i % a[3] && i % a[4] && i % a[5]) {
			a[++j] = i;
			if (line % 10 == 0) {
				cout << endl;
			}
			cout << i <<',';
			line++;
		}
	}
}
 
// 判断并输出100~10000的质数
void solve10000()
{
	for (int i = 101; i < 10000; i++) {
		bool flag = true;
		for (int k = 2; k <= j; k++) {
			if (i % a[k] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (line % 10 == 0) {
				cout << endl;
			}
			cout << i <<',';
			line++;
		}
	}
}
 
int main()
{
	// 先直接输出10以内的质数
	a[0] = 0;
	a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 5, a[5] = 7;
	cout << a[2]<<',';
	cout << a[3]<<',';
	cout << a[4]<<',';
	cout << a[5]<<',';
	line = 4;
 
	solve100();
 
	solve10000();
	cout << "\n10000以内质数个数为: " << line<< endl;
	
	return 0;
}
