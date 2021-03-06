#pragma once
typedef struct Node{
    int data;///密码值
    int order;///编号（这个不随元素的删除而改变）
}Node;
typedef struct LIST{
    Node* node;///建表之后，这个域会成为结构体数组
    int cur;///指向当前元素的指针
    int Length;///记录表长
}LIST,*List;
///由于条件比较特殊，这里的顺序表实现起来也不太一样233

void CreateList(List L,int n);///生成一个node元素长度为n的表，并初始化好，返回表头指针

bool IsEmpty(List L);///检测表L是否为空表

void InsertElem(List L,int i,int m,int order);///在L表中的第i个元素后插入密码值为m的新元素

void DeleteElem(List L, int &mPtr,int &order);
///从表L中删除第m个元素，并将该元素的m密码值用mPtr写到原m的地址上，
///并将表头指向移动到m的下一个元素位置处（这是与正常的del函数不同的地方）
///用order带回所删除的元素的编号
//#endif /*SqList*/

void DestroyList(List L);///销毁表L