#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m;
int a[N],r[N],g[N];//每个路口间的距离，红灯时间（red），绿灯时间（green）
int main(){
    cin>>n>>m;//读入
    for(int i=1;i<n;i++){//记住，有n个路口，只有n-1个距离
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//读入红灯时间
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){//读入绿灯时间
        cin>>g[i];
    }
    for(int i=1;i<=n;i++){//对时间进行处理
        if(m%(r[i]+g[i])>g[i])m+=(r[i]+g[i])-m%(r[i]+g[i]);//如果当前时间不在绿灯范围内，就将m加上当前时间与最近的当前路口的绿灯的时间差
        cout<<m<<endl;//输出时间
        m+=a[i];//加上通过第i到i+1个路口间距离的时间
    }
    return 0;
}
