#pragma once
#include"DCLinkedList.h"
#define m_MAX 100000///�������������������m�ķ�Χ

void mRandomize(int& m);//��m�����ֵ

void Randomize(int n, int& m, List L);///�����ʼ������
///����������n����������ĳ�ʼ����m0���������ʼ����ɵĻ�L

void Josephus(int m, List L, int* popOrder);///��˫ѭ������ģ��Լɪ�򻷵ĺ���
///����������n����ʼ����m���������ɻ�L
///�������˳�˳�������
