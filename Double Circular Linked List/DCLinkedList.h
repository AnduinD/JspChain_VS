#pragma once
#define DEBUG 0     //0：把多组数据输出到文件以记录；1：在控制台调试

//用双向循环链表实现
typedef struct Node {
    int order;//每个人的编号
    int data;//每个人手中的密码值
    struct Node* next;//指向下一元素的指针
    struct Node* prior;//指向前一元素的指针
}Node;

typedef struct LIST {
    //双循环链表用头指针封装一波
    Node* head;
}*List;

void CreateList(List L, int n);///生成一个node元素长度为n的表，并初始化好，返回表头指针

int getLength(List L);//返回表L的长度

bool IsEmpty(List L);///检测表L是否为空表

void InsertElem(List L, int i, int m, int order);///在L表中的第i个元素后插入密码值为m的新元素

void DeleteElem(List L, int& mPtr, int& order);
///从表L中删除第m个元素，并将该元素的m密码值用mPtr写到原m的地址上，
///并将表头指向移动到m的下一个元素位置处（这是与正常的del函数不同的地方）
///用order带回所删除的元素的编号

void DestroyList(List L);///销毁表L
