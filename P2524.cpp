#include<bits/stdc++.h>
using namespace std;
long a[10],b[10],n,m,k,ans=0;
bool c[10];
inline bool pig2()
{
    ans++;  //������һ
    for (long i=1;i<=n;i++)
        if (a[i] != b[i]) return false;  //�ж��Ƿ���ͬ
    return true;
}
inline void pig(long t)
{
    if (t > n) 
    {
        if (pig2()) cout<<ans<<endl;  //����������� 
        return;
    }
    for (long i=1;i<=n;i++)
        if (! c[i])
        {
            b[t]=i;  
            c[i]=1;  //����
            pig(t+1);
            c[i]=0;  //����
        }
}
int main()
{
    long i;
    cin>>n;
    cin>>k;
    for (i=n;i>=1;i--)  //�ֽ�
    {
        a[i]=k%10;
        k/=10;
    }
    memset(c,false,sizeof(c));
    pig(1);
    return 0;
}

