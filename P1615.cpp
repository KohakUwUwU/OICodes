#include <stdio.h>
long long a, b, c, x, y, z, t,hs=3600,ms=60,ss=1;int main(){return scanf("%lld:%lld:%lld\n%lld:%lld:%lld\n%lld", &a, &b, &c, &x, &y, &z, &t), printf("%lld", ((x - a) * hs + (y - b) * ms + (z - c) * ss) * t) % 1;}
