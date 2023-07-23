#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long long ull;

inline ull gcd(ull a, ull b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}

inline ull lcm(ull a, ull b)
{
    return a / gcd(a, b) * b;
}

inline ull lcm(ull a, ull b, ull c)
{
    return lcm(a, lcm(b, c));
}

inline ull lcm(ull a, ull b, ull c, ull d, ull e, ull f)
{
    return lcm(lcm(a, b, c), lcm(d, e, f));
}

inline ull term(ull a, ull b, ull c)
{
    return lcm(a, c) * gcd(b, c) / gcd(a, b);
}

int main()
{
    ull n = 1, result = 1, x, y;
    ofstream fout("out.txt");
    if (!fout.is_open()) return 1;

    while (++n)
    {
        for (x = 1; x <= n - 2; x++)
            for (y = x + 1; y <= n - 1; y++)
                result += 6 * lcm(term(x, y, n), term(x, n, y), term(y, x, n),
                    term(y, n, x), term(n, x, y), term(n, y, x));

        for (x = 1; x <= n - 1; x++)
            result += 3 * (lcm(x, n, lcm(x, n) * x / gcd(x, n))
                + lcm(x, n, lcm(x, n) * n / gcd(x, n)));

        result += n;

		printf("%lld %lld\n",n,result);
        fout << result << ",\n";
    }
    return 0;
}

