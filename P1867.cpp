#include<bits/stdc++.h>
using namespace std;
int main()
{
	double js = -1,rank = 1;//目前拥有的经验和等级
	double hp = 10;//血量 
	double a,b;
	int n;
	scanf("%d",&n);
	int shengji = 2;//第一次升级需要的经验是2 
	for(int i = 1;i <= n;++ i)
	{
		scanf("%lf%lf",&a,&b);
		hp -= a;//血量减去输入的需要消耗的，负的就变成了家 
		if(hp > 10)//大于最大血量的时候变为10 
			hp = 10;
		if(hp <= 0)//血量低于或者等于下线的时候输出现在的等级结束 
		{
			if(js == -1 && rank == 1)//最特殊的地方，也是最坑人的地方 
			{//当等级为1但是经验却是0的话那就是没得到经验但是一级之前还是需要减去一个1的所以这里就只能特判输出0 0了 
				cout<<"0"<<" "<<"0"<<endl;
				return 0; 
			}	 
			printf("%g %g\n",rank,js);//其他的情况正常输出 
			return 0;
		}
		js += b;
		while(js >= shengji)//结束条件，避免一次操作升级多次的情况 
		{
			js -= shengji;//经验减去 
			rank ++;//等级累加 
			shengji = pow(2,rank);//继续增加升级所需要的经验 
		}
	}
	if(js == -1 && rank == 1)//同上面的特判 
	{
		cout<<0<<" "<<0<<endl;
		return 0;
	} 
	printf("%g %g\n",rank,js);//其他情况非特殊的 
	return 0;
}
