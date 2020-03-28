#pragma once
#include"DCLinkedList.h"
#define m_MAX 100000///改这个参数来调整生成m的范围

void mRandomize(int& m);//给m赋随机值

void Randomize(int n, int& m, List L);///随机初始化函数
///输入总人数n，带回随机的初始密码m0，和随机初始化完成的环L

void Josephus(int m, List L, int* popOrder);///用双循环链表模拟约瑟夫环的函数
///输入总人数n，初始密码m，和已生成环L
///带回人退出顺序的序列
