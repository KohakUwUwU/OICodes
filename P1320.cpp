#include <bits/stdc++.h>
int d[40020],i=1;
char c;
int main()
{
    for(;scanf("%c",&c)&&c>0x2F;)i+=!(i&1^(c-0x30)),d[i]++,d[0]++;
    for(;~scanf("%c",&c);)if(c>0x2F)i+=!(i&1^(c-0x30)),d[i]++;
    for(int j=0;j<=i;j++)printf("%d ",d[j]);
}
