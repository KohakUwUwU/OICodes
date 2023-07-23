#include<stdio.h>
int ans,r,b,c,d,e;
int main(){ scanf("%d%d%d%d%d",&r,&b,&c,&d,&e); ans=(c+d>2*e?r*c+b*d:(r>b?b*2*e+(r-b)*c:r*2*e+(b-r)*d)); printf("%d",ans);}
