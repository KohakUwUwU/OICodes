#include<bits/stdc++.h>
using namespace std;

int main()
{

   int n;
   cin>>n;
   int n_sqrt = sqrt(n);
   //循环截至条件到根号n就行
   //从2开始，遇到的第一个因数，一定是质数
   //比如24，遇到了2，就一直除，直到余数不为0
   //有人说，4也是24的因数啊，但是不是质数
   //这个在遇到2时，一直除，这里已经将4除掉了
   //24已经变成3了
   for(int i=2;i<=n_sqrt;i++)
   {
       if(n%i==0)//
       {
           while(n%i==0)
           {
                n/=i;
                cout<<i<<endl;
           }
       }
   }
   //像24这样的数 ，24 = 2*2*2*3，最后n变成了1
   //但是像22这样的数，22=2*11，但是11>sqrt(22),所以需要判断一下
   //又如11这样的数，11 = 11*1，这个判断也能处理
   if(n!=1) cout<<n<<endl;
    return 0;
}


