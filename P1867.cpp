#include<bits/stdc++.h>
using namespace std;
int main()
{
	double js = -1,rank = 1;//Ŀǰӵ�еľ���͵ȼ�
	double hp = 10;//Ѫ�� 
	double a,b;
	int n;
	scanf("%d",&n);
	int shengji = 2;//��һ��������Ҫ�ľ�����2 
	for(int i = 1;i <= n;++ i)
	{
		scanf("%lf%lf",&a,&b);
		hp -= a;//Ѫ����ȥ�������Ҫ���ĵģ����ľͱ���˼� 
		if(hp > 10)//�������Ѫ����ʱ���Ϊ10 
			hp = 10;
		if(hp <= 0)//Ѫ�����ڻ��ߵ������ߵ�ʱ��������ڵĵȼ����� 
		{
			if(js == -1 && rank == 1)//������ĵط���Ҳ������˵ĵط� 
			{//���ȼ�Ϊ1���Ǿ���ȴ��0�Ļ��Ǿ���û�õ����鵫��һ��֮ǰ������Ҫ��ȥһ��1�����������ֻ���������0 0�� 
				cout<<"0"<<" "<<"0"<<endl;
				return 0; 
			}	 
			printf("%g %g\n",rank,js);//���������������� 
			return 0;
		}
		js += b;
		while(js >= shengji)//��������������һ�β���������ε���� 
		{
			js -= shengji;//�����ȥ 
			rank ++;//�ȼ��ۼ� 
			shengji = pow(2,rank);//����������������Ҫ�ľ��� 
		}
	}
	if(js == -1 && rank == 1)//ͬ��������� 
	{
		cout<<0<<" "<<0<<endl;
		return 0;
	} 
	printf("%g %g\n",rank,js);//�������������� 
	return 0;
}
