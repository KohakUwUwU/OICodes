#include <iostream>
using namespace std;

const int maxn=100001;

int N, M, K;
int x[maxn], y[maxn], d[maxn];
int c[maxn];
int *a[maxn];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> x[i] >> y[i] >> d[i]; //表示第x[i]行第y[i]列的值为 d[i]
        c[y[i]]++;
    }
    for (int i = 1; i <= M; ++i)
        a[i] = new int[c[i]];
    for (int i = 0; i < K; ++i) {
        *a[y[i]] = d[i];
        a[y[i]]++;
    }

    for (int i = 1; i <= M; ++i) {
        a[i] = a[i] - c[i];
        for (int j = 0; j < c[i]; ++j, ++a[i])
            cout << *a[i] << ' ';
    }
    return 0;
}
