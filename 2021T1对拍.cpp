#include <stdio.h>
#include <stdlib.h>
int main() {
  // For Windows
  //����ʱ�����ļ��������
  //��Ȼ����γ���Ҳ���Ը�д�����������ʽ
  while (true) {
    system("gen > test.in");  //��������������������д�������ļ�
    system("test1.exe < test.in > a.out");  //��ȡ����1���
    system("test2.exe < test.in > b.out");  //��ȡ����2���
    if (system("fc a.out b.out")) {
      // �������ȶ��������
      // fc����0ʱ��ʾ���һ�£������ʾ�в�ͬ��
      system("pause");  // ����鿴��ͬ��
      return 0;
      // �����������Ѿ������test.in�ļ��У�����ֱ�����ý��е���
    }
  }
}
