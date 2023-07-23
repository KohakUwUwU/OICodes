#include<cstdio>
bool pd(long long n)
{
    if(n==1)
        return false;
    for(long long i=2;i<n;i++)
        if(n%i==0)return false;
    return true;
}
int main()
{
    long long n,i,c=0;
    int INF=1<<30;
    scanf("%lld",&n);
    for(i=2;i<=INF;i++)
    {
        if(pd(i))
        {
            c++;
            if(c==n)
            {
                printf("%lld",i);
                return 0;
            }
        }
    }
    printf("\nover");
    return 0;
}
