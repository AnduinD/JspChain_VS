#pragma once
#define DEBUG 0
#include"SqList.h"

void Randomize(int n,int &m,List L);///�����ʼ������
///����������n����������ĳ�ʼ����m0���������ʼ����ɵĻ�L

void Josephus(int m,List L,int *popOrder);///��˫ѭ������ģ��Լɪ�򻷵ĺ���
///����������n����ʼ����m���������ɻ�L
///�������˳�˳�������
