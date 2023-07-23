#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[100][100];
int f(int m,int n){
    if (m <= 0 || n <= 0)
        return 0;
    a[0][0] = b[0][0];
     for(int i=1;i<n;i++)a[0][i]=a[0][i-1]+b[0][i];
     for(int i=1;i<m;i++)a[i][0]=a[i-1][0]+b[i][0];
     for(int i=1;i<m;i++){
         for(int j=1;j<n;j++){
             a[i][j]=min(a[i-1][j],a[i][j-1])+b[i][j];
         }
     }
     return a[m-1][n-1];
}
int main(){
     int m,n;
     cin>>m>>n;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             cin>>b[i][j];
         }
     }
     cout<<f(m,n);
     return 0;
}
