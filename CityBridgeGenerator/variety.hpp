#pragma once
#include"typeheader.hpp"
#include"xoy.hpp"
const int N=1e5+7;//��Ԫ������ 
const int M=2e5+7;//���������� 
const double EPS=1e-4;
const double PI=3.14159;
const double HOMO=114514;
const Range EmptyRange=(Range){114514,-114514};
Element Data[N];//Ԫ���ڴ�� 
int ElementCnt;//Ԫ�ظ���
BridgeInfo bridge[M];//������Ϣ�ڴ��
int BridgeCnt;//�������� 
vector<int>Bri[M];//������ͨ��� 
bool vis[N];
//��ʾԪ���Ƿ�Ϊ����Ԫ�أ�
//���Ϊ����Ԫ�أ����������ʱ����Ա�����Ϊ�ݹ���ڵ㣬���ýڵ�Ϊ��Ԫ����Ĵ���Ԫ�أ�������Ϊtrue 
//���Ϊ����Ԫ�أ����������ʱ�򲻿��Ա�ֱ�ӵ��ã����ýڵ㲻�Ǹ�Ԫ����Ĵ���Ԫ�أ�������Ϊfalse
//tips:����������vis�����ָ���Ԫ���飡���� 
//����vis[4]={0,1,1,0};
//������Ϊ1->2->3
//�������ʱ������1->2->3 2->3 
//��ֹ���� 
