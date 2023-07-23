#include <iostream>
using namespace std;

int a[101], d[101];

int main() {
    int n = 5;
    a[1] = d[1] = 1;
    for (int i = 1; i <= n; ++i) {
        int s = i + 1, x = 0;
        for (int j = 1; j <= n + 1 - i; ++j) {
            int k = s + x;
            x++;

            a[j + 1] = a[j] + k;
            cout << a[j] << ' ';
        }
        cout << "..." << endl;
        a[1] = d[i + 1] = d[i] + i;
    }
    return 0;
}
