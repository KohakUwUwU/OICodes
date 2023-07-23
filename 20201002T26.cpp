#include <iostream>
#include <iomanip>
using namespace std;

int m[101][101];

int main() {
    int a;
    cin >> a;

    int c = a * a, i = 1, k = (a + 1) / 2;
    for (int j = 1; j <= c; j++) {
        m[i][k] = j;
        if (j % a == 0) {
            if (i == a)
                i = 1;
            else
                i++;
        } else {
            if (i == 1)
                i = a;
            else
                i--;

            if (k == a)
                k = 1;
            else
                k++;
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++)
            cout << setw(5) << m[i][j];
        cout << endl;
    }
    return 0;
}
