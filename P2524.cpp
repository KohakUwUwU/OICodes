#include<bits/stdc++.h>
using namespace std;
long a[10],b[10],n,m,k,ans=0;
bool c[10];
inline bool pig2()
{
    ans++;  //个数加一
    for (long i=1;i<=n;i++)
        if (a[i] != b[i]) return false;  //判断是否相同
    return true;
}
inline void pig(long t)
{
    if (t > n) 
    {
        if (pig2()) cout<<ans<<endl;  //满足条件输出 
        return;
    }
    for (long i=1;i<=n;i++)
        if (! c[i])
        {
            b[t]=i;  
            c[i]=1;  //搜索
            pig(t+1);
            c[i]=0;  //回溯
        }
}
int main()
{
    long i;
    cin>>n;
    cin>>k;
    for (i=n;i>=1;i--)  //分解
    {
        a[i]=k%10;
        k/=10;
    }
    memset(c,false,sizeof(c));
    pig(1);
    return 0;
}

