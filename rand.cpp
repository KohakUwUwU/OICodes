/*
������ʵ�ֵĹ��ܣ�
����1000��������ظ���������������������� 
������������Щ�������õ�ʱ�� 
*/
#include <iostream>
#include <ctime> // time.hҲ��,���ڼ����������ʱ���������������� 
using namespace std;
#define SELF_RAND_MAX 0x7FFFFFFF
int main()
{
 //typedef long clock_t 
 clock_t start_time = clock();//��ʱ��ʼ
 
    srand(unsigned(time(0)));//����ʱ������
 //���ɵ���ֵ��1000��1000��֮�� 
    const int MAX = 46;
    const int MIN = 1;
    /*�������� freopen("in.txt","r",stdin); 
 //д������ freopen("out.txt","w",stdout);
 //fclose(stdin);//�ر��ļ� 
    //fclose(stdout);//�ر��ļ� 
    �ѱ�׼������stdin�ض���in.txt�ļ��У�
 ��������scanf������cin����ʱ�㲻��ӱ�׼��������ȡ����,
 ���Ǵ�in.txt�ļ��л�ȡ���롣
 ֻҪ��������������ճ����in.txt������ʱ�ͷ�����ˡ� 
    */
  freopen("data.txt","w",stdout);
  //cout << "---Generate 10,000,000 random numbers\
  //         which maybe repeated---" << endl;
 for(int i = 0; i < 100; ++i){
  //#define RAND_MAX 0x7FFF
    //�ϱ�׼unsigned long data = ( MAX * rand() )/ ( RAND_MAX + MIN)+ 1;
    //unsigned long data = (MAX - MIN + 1 ) * rand() + MIN;
   //unsigned long data = ((MAX - MIN + 1 ) * rand()   + MIN) % 10000000;
   unsigned long data = rand() % (MAX - MIN + 1) + MIN;//�ϱ�׼ 
    cout << data << ' '; //������ݵ�data.txt 
 }
 fclose(stdout);
 freopen("time.txt","w",stdout);
 cout << endl 
      << "---the end---" 
   << endl;
   //CLOCKS_PER_SEC���ƾ��ȣ���windows��������1000,linux���Ƕ�������
   //�򵥵�˵windows���Ǻ��뼶����linux�������뼶 
    cout << "elapsed time:" << double(clock() - start_time) / CLOCKS_PER_SEC
         << 's' << endl;
  //  fclose(stdout);
}
