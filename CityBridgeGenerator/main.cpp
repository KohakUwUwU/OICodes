//Written by MRKR-Ame (Huang Ziyang)
/*
���Ч����
�û����뽨��ģ����Ϣ������/����������Ϣ����Ҫ�ﵽ�Ľ�����ͨ�����ͨ������������������û��û�����������Ҫ�أ� 
����Ϲ��µ�������ģ��Դ���������������OpenSCAD�н�����Ⱦ 
�������̣�
�û�ʹ�ÿ⺯����д����ģ�͵���Ϣ�������� -> ���뷭����&���������з�������������ŵĽ���ģ��Դ�루SCAD�� -> �û���SCAD�ֶ���Ⱦ
ʵ��ϸ�ڣ�
������Ҫ�������Ͷ���ͷ�ļ�������ͷ�ļ�����Ϣ����ͷ�ļ���ģ�ʹ���ͷ�ļ���Դ�����ͷ�ļ� 
�û������Զ������Ԫ�أ�������Ҫ�����ڴ�ص��н��д��棨��������ʽ��
 
������дϸ�ڣ�
����OpenSCAD�Ĺ��ܽ��ܺʹ����﷨������գ�
https://zh.wikibooks.org/wiki/OpenSCAD%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C
Ԫ�ش������ڴ�ص���
Ԫ�ص��д洢Ԫ�ز����б����η��б� 
�ڴ�ص���Ԫ�ز���������ʵ���ʽ��ʵ��ȡ����ȡ������ȡ����
������Ͷ���ͷ�ļ� 
*/
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma once
#include<bits/stdc++.h>
#include"typeheader.hpp"
#include"variety.hpp"
#include"input.hpp"
#include"process.hpp"
#include"output.hpp"
#include"xoy.hpp"
#include"Fx3D.hpp"
#define int long long
using namespace std; 
signed main()
{
	Input_Element();
	//��Ԫ���ڴ�ص�������Ԫ����Ϣ
	Input_Connectivity();
	//���뽨��/���������Լ���ͨ��Ϣ 
	if(Process()==0)Output();
	//�������������Դ�� 
	return 0;
}
