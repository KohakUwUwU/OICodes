#include<iostream>
using namespace std;
int tong[3]={4,6,5},mei[3]={1,2,3};//上 前 右的骰子数字 
int n,sum1,sum2;
void setDice(char ch,int child[])
{
	int up,front,right;
	switch(ch)
	{
		case 'R':{
			up=7-child[2];
			front=child[1];
			right=child[0];
			break;
		}
		case 'D':{
			up=7-child[1];
			front=child[0];
			right=child[2];
			break;
		}
		case 'L':{
			up=child[2];
			front=child[1];
			right=7-child[0];
			break;
		}
	}
	child[0]=up;child[1]=front;child[2]=right;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int a=(2*i-1)%4,b=(2*i)%4;//骰子转动次数 
		switch(i%3)
		{
			case 1:{
				while(a--){
					setDice('R',tong);
				}
				sum1+=tong[0];
				while(b--)
				{
					setDice('R',mei);
				}
				sum2+=mei[0];
				break;
			}
			case 2:{
				while(a--){
					setDice('D',tong);
				}
				sum1+=tong[0];
				while(b--)
				{
					setDice('D',mei);
				}
				sum2+=mei[0];
				break;
			}
			case 0:{
				while(a--){
					setDice('L',tong);
				}
				sum1+=tong[0];
				while(b--)
				{
					setDice('L',mei);
				}
				sum2+=mei[0];
				break;
			}
		}
	}
	if(sum1>sum2)cout<<'A';
	else if(sum1==sum2)cout<<'D';
	else cout<<'B';
}
