#include<cstdio>
using namespace std;
long double a,sum;
int main()
{
    if(scanf("%Lf",&a)!=EOF)
    {
        sum+=a*1000000;
        main();
    }
    else printf("%.5Lf",sum/1000000);
    return 0;
}
