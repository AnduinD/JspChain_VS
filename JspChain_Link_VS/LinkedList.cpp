#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

void CreateList(List L,int n)
{//这个读入的n没啥用，只是为了和Sq的统一
    L->head= NULL;
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
        while(p!=L->tail)
        {
            p = p->next;
            Length++;
        }
        return Length;
    }
}

bool IsEmpty(List L)
{
    return (L->head == NULL&&L->tail==NULL); //是否仅有头尾结点
}

void InsertElem(List L, int i, int m,int order)
{
    if (IsEmpty(L))     //表L为空表的情形
    {
        Node *temp = (Node *)malloc(sizeof(Node));
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

void DeleteElem(List L, int &m, int &order)
{

   // if (L->next->next != L->next) //表里有不只一个结点的时候
    if(L->head!=L->tail) //表里有不只一个结点的时候
    {
        Node* cur = L->head;
        Node* pre=L->tail;
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
        temp=NULL;
    }
    free(L);
}
