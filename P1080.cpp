//And in that light, I find deliverance.
#include<bits/stdc++.h> 
#define int long long
using namespace std;
struct ppl
{
    int a,b;
}p[1005];
int n,x,sum[3000],ans[3000],divn[3000];
inline bool cmp(ppl x,ppl y)
{
    return x.a*x.b<y.a*y.b;
}
inline void compare()
{
    for(int k=max(ans[0],divn[0]);k>0;k--)
	{
        if(ans[k]>divn[k])return;
        if(ans[k]<divn[k])
		{
            for(int j=0;j<=divn[0];j++)ans[j]=divn[j];
            return;
        }
    }
    return;
}    
signed main()
{
    cin>>n;
    for(int i=0;i<=n;i++)cin>>p[i].a>>p[i].b;
    sort(p+1,p+n+1,cmp);
    sum[0]=1,sum[1]=1;
    for(int i=1;i<=n;i++)
	{
        x=0;
        for(int j=1;j<=sum[0];j++)
		{
            sum[j]=sum[j]*p[i-1].a+x;
            x=sum[j]/10000;
            sum[j]%=10000;
        }
        if(x>0)sum[0]++,sum[sum[0]]=x;
        x=0;
        memset(divn,0,sizeof(divn));
        for(int j=sum[0];j>0;j--)divn[j]=(x*10000+sum[j])/p[i].b,x=(x*10000+sum[j])%p[i].b;
        divn[0]=sum[0];
        while(divn[divn[0]]==0)divn[0]--;
        compare();
    }
    cout<<ans[ans[0]];
    for(int i=ans[0]-1;i>0;i--)cout<<ans[i]/1000<<ans[i]/100%10<<ans[i]/10%10<<ans[i]%10;
    return 0;
}
