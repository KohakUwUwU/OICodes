#include<iostream>
using namespace std;
int n,m,a2[102][102],fx[10]={0,1,0,-1,0,1,-1,1,-1},fy[10]={0,0,1,0,-1,-1,1,1,-1};//枚举
char a[102][102];
void dfs(int x,int y){
	for(int i=1;i<=8;i++){
		int xx=x+fx[i],yy=y+fy[i];
		if(a[xx][yy]=='*'&&xx>=1&&xx<=n&&yy>=1&&yy<=m)//判断是否合格
			a2[x][y]++;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){
			if(a[i][j]!='*'){
				dfs(i,j);
				cout<<a2[i][j];//找到不是零的
			}
			else
			 	cout<<"*";//不然照样输出
		}
		cout<<endl;
	} 
	return 0;
}
