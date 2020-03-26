#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#define ERROR printf("STACK OVERFLOW")

#if LINKED_LIST
void CreateList(List L, int n)
{//这个读入的n没啥用，只是为了和Sq的统一
    L->head = NULL;
    L->tail = NULL;
    //L->prior = NULL; 
    //只是头结点而非首元结点，
    //故此时链表虽然有一个结点，
    //但实际数据元素个数为空
}
int getLength(List L)
{
    if (IsEmpty(L)) return 0;//空表
    else
    {
        Node* p = L->head;
        int Length = 1;//先把首元算上
        //while (p->next != L->head->next/*&&p->next!=NULL*/)
        while (p != L->tail)
        {
            p = p->next;
            Length++;
        }
        return Length;
    }
}

bool IsEmpty(List L)
{
    return (L->head == NULL && L->tail == NULL); //是否仅有头尾结点
}

void InsertElem(List L, int i, int m, int order)
{
    if (IsEmpty(L))     //表L为空表的情形
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;
        //temp->prior = temp;
        L->head = temp;
        L->tail = temp;
        temp->next = temp;
        //free(temp);
        //temp=NULL;
    }
    else//表非空的时候
    {
        Node* ins = L->head; //声明一个Node指针指向L的首元
        //printf("here");
        for (; i > 1; i--) //把ins指针漫游到待插入的位置前面
        {
            ins = ins->next;
            //printf("there");
        }

        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;

        temp->next = ins->next;
        ins->next = temp;
        if (temp->next == L->head) L->tail = temp;//如果在原来的尾结点之后插入，则把tail改一下
        //temp->prior = ins;
        //temp->next->prior = temp;
        //temp->prior->next = temp;

        //free(temp);
        //temp = NULL;
    }
}

void DeleteElem(List L, int& m, int& order)
{

    // if (L->next->next != L->next) //表里有不只一个结点的时候
    if (L->head != L->tail) //表里有不只一个结点的时候
    {
        Node* cur = L->head;
        Node* pre = L->tail;
        //声明两个Node指针指向L的表头元素，在遍历后分别指向待删除的结点和它的前驱结点
        for (int i = 1; i <= m; i++)//把cur移动到待删除元素的头上
        {
            pre = pre->next;
            cur = cur->next;
        }
        //while (pre->next != cur) pre = pre->next;///单循环链表一个贼缺陷的地方
        ///如果删除首元的话，pre指针得把整个表跑一遍，淦
        //有一个方法是给循环链表加一个尾结点，感觉还不错？类似头节点的样子。

        L->head = cur->next;//把表头接过来先
        L->tail = pre;

        ///进行删除时的指针域调整
        pre->next = cur->next;
        cur->next = NULL;

        ///带出所需的值
        order = cur->order;
        m = cur->data;

        free(cur);
        cur = NULL;
    }
    else//只剩一个结点的时候
    {
        Node* temp = L->head;
        temp->next = NULL;
        L->head = NULL;
        L->tail = NULL;

        ///带出所需的值
        order = temp->order;
        m = temp->data;

        free(temp);
        temp = NULL;
    }
}

void DestroyList(List L)
{
    while (!IsEmpty(L))
    {
        Node* temp = L->head;
        L->head = temp->next;
        free(temp);
        temp = NULL;
    }
    free(L);
}
#endif //LINKED_LIST

#if SQ_LIST
void CreateList(List L, int n)///生成一个node元素长度为n的表，并初始化好，返回表头指针
{
    if (L == NULL) { ERROR; return; }//如果给L的地址分派失败则报错
    L->node = (Node*)malloc(n * sizeof(Node));//给node一次性分配地址
    if (L->node == NULL) { ERROR; return; }//如果给node的地址分派失败则报错
    L->cur = 0;//初始化cur的位置
    L->Length = 0;//初始化L的长度值
}

int getLength(List L)
{
    return L->Length;
}

bool IsEmpty(List L)///检测表L是否为空表
{
    return (L->Length) ? false : true;
}

void InsertElem(List L, int i, int m, int order)///在L表中的第i个元素后插入密码值为m的新元素
{
    L->Length += 1;
    for (int j = L->Length - 1; j > i; j--)//把i之后的元素全部向后移动
    {
        L->node[j].data = L->node[j - 1].data;
        L->node[j].order = L->node[j - 1].order;
    }

    L->node[i].data = m;//在i后面录入新的元素的值
    L->node[i].order = order;

    //printf("insert order=%d\ninsert data=%d\n", L->node[i].order,L->node[i].data);
}

void DeleteElem(List L, int& m, int& order)
///从表L中删除从cur往后数的第m个元素，并将该元素的m密码值用mPtr写到原m的地址上，
///并将cur指向m的下一个元素位置处（这是与正常的del函数不同的地方）
///用order带回所删除的元素的编号
{
    for (int i = 0; i < m; i++)///游动cur到第m个元素的头上
    {
        L->cur++;
        if (L->cur == L->Length) L->cur = 0;///超出队尾时回到队头
        //!!!!!!这里有错！！！！不能改L.Length,但有遍历不到！！！
        ///所以还是回归低效的移动一条数的办法吧~~
        //if(L->node[L->cur].is_inChain==false) i--;///如果遍历到已出环的元素，则这次遍历不算，把i退回一格
        //while (L->node[L->cur].is_inChain == false) L->cur++;
    }

    ///带出所需的值
    m = L->node[L->cur].data;
    order = L->node[L->cur].order;

    L->Length -= 1;
    for (int j = L->cur; j < L->Length; j++)//把cur后的元素往前移动
    {
        L->node[j].data = L->node[j + 1].data;
        L->node[j].order = L->node[j + 1].order;
    }
    if (L->cur == L->Length)
        L->cur = 0; //如果删除的是表尾的元素，记得把cur移到头（从它顺时针的下一个元素开始转）
}

void DestroyList(List L)
{
    free(L->node);
    L->node = NULL;
    free(L);
    L = NULL;
}

#endif //SQ_LIST