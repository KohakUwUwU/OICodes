
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
 
int a[30]; // ���ڴ��100���ڵ�����
int j = 5;
int line = 0;
 
// �����100���ڵ�������������洢��
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
 
// �жϲ����100~10000������
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
	// ��ֱ�����10���ڵ�����
	a[0] = 0;
	a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 5, a[5] = 7;
	cout << a[2]<<',';
	cout << a[3]<<',';
	cout << a[4]<<',';
	cout << a[5]<<',';
	line = 4;
 
	solve100();
 
	solve10000();
	cout << "\n10000������������Ϊ: " << line<< endl;
	
	return 0;
}
