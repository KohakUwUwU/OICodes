#include<bits/stdc++.h>
int main(){
        int c,s=0,h=0;                        //c=每个月花的钱，s=自己手里的钱，h=存给麻麻的红色毛爷爷数量
        for(int i=1;i<=12;i++)            //从一月循环到十二月
        {
                scanf("%d",&c);                   //读入每个月花的钱
                s-=c-300;                          //等效于s=s+300-c，算出这个月过去之后还剩多少钱
                if(s<0)                               //如果（“哇这个月过去之后我就没钱了！”）
                {
                        printf("-%d",i);
                        return 0;
                }
                else h+=s/100,s%=100;
        }
        printf("%d",120*h+s);
        return 0;
}
