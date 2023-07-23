#include <iostream>
using namespace std;
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
  CP operator / (CP const &B) const {
    double t=B.x*B.x+B.y*B.y;
    return CP((x*B.x+y*B.y)/t,
              (y*B.x-x*B.y)/t);
  } 
}a,b;
int main()
{
  cin>>a.x>>a.y>>b.x>>b.y;
  CP c;
  c=a+b;
  cout<<'('<<c.x<<','<<c.y<<")\n";
  c=a-b;
  cout<<'('<<c.x<<','<<c.y<<")\n";
  c=a*b;
  cout<<'('<<c.x<<','<<c.y<<")\n";
  c=a/b;
  cout<<'('<<c.x<<','<<c.y<<")\n";
  return 0;
}
