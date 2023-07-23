#include<iostream> 
using namespace std;  
int a[100002],m,n,i,s,p,j,minn,ans,maxx;
int main()  
{  
    cin>>n>>m;
    for(i=1;i<=m;i++)  
        cin>>a[i];
     for(i=1;i<=m;i++)   
         {p=a[i];  
          s=0;  
          for(j=1;j<=m;j++)  
              if(a[j]>=p)s++;  
              if(s>=n)s=n;  
              if(p*s>maxx)  
                 {maxx=p*s;ans=p;}
        }cout<<ans<<" "<<maxx;
}
