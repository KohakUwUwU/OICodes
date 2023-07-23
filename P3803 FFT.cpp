#include<algorithm>
#include<cstdio>
#include<cmath>
#define Maxn 1350000
using namespace std;
const double Pi=acos(-1);
inline int read()
{
  register char ch=0;
  while(ch<48||ch>57)ch=getchar();
  return ch-'0';
}
int n,m;
struct CP
{
  CP (double xx=0,double yy=0){x=xx,y=yy;}
  double x,y;
  CP operator + (CP const &B) const
  {return CP(x+B.x,y+B.y);}
  CP operator - (CP const &B) const
  {return CP(x-B.x,y-B.y);}
  CP operator * (CP const &B) const
  {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
}f[Maxn<<1];//只用了一个复数数组 
int tr[Maxn<<1];
void fft(CP *f,bool flag)
{
  for (int i=0;i<n;i++)
    if (i<tr[i])swap(f[i],f[tr[i]]);
  for(int p=2;p<=n;p<<=1){
    int len=p>>1;
    CP tG(cos(2*Pi/p),sin(2*Pi/p));
    if(!flag)tG.y*=-1;
    for(int k=0;k<n;k+=p){
      CP buf(1,0);
      for(int l=k;l<k+len;l++){
        CP tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tG;
      }
    }
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  for (int i=0;i<=n;i++)f[i].x=read();
  for (int i=0;i<=m;i++)f[i].y=read();
  for(m+=n,n=1;n<=m;n<<=1);
  for(int i=0;i<n;i++)
    tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
  fft(f,1);
  for(int i=0;i<n;++i)f[i]=f[i]*f[i];
  fft(f,0);
  for(int i=0;i<=m;++i)
    printf("%d ",(int)(f[i].y/n/2+0.49));
  return 0;
}
