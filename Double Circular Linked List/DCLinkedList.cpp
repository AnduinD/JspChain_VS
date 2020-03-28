#include<stdio.h>
#include<stdlib.h>
#include"DCLinkedList.h"
#define ERROR printf("STACK OVERFLOW")

void CreateList(List L, int n)
{//这个读入的n没啥用，只是为了和Sq的统一
    L->head = NULL;
    //L->prior = NULL; 
    //这个链表头就是把一个指针封装改个名，没啥特别的
    //顶多算个头结点，只是这个结点没有数据域
}
int getLength(List L)
{
    if (IsEmpty(L)) return 0;//空表
    else
    {
        Node* p = L->head;
        int Length = 1;//先把首元算上
        while (p->next != L->head)
        {
            p = p->next;
            Length++;
        }
        return Length;
    }
}

bool IsEmpty(List L)
{
    return (L->head == NULL ); //是否仅有头结点
}

void InsertElem(List L, int i, int m, int order)
{
    if (IsEmpty(L))     //表L为空表的情形
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;
        L->head = temp;
        temp->next = temp;
        temp->prior = temp;
    }
    else//表非空的时候
    {
        Node* ins = L->head; //声明一个Node指针指向L的首元
        
        for (; i > 1; i--) //把ins指针漫游到待插入的位置前面
        {
            ins = ins->next;
        }

        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;

        temp->next = ins->next;
        temp->prior = ins;
        temp->next->prior = temp;
        temp->prior->next = temp;
    }
}

void DeleteElem(List L, int& m, int& order)
{
    if (L->head->next==L->head) //只剩一个结点的时候
    {        
        L->head->next = L->head->prior=NULL;
        ///带出所需的值
        order =L->head->order;
        m = L->head->data;

        free(L->head);
        L->head = NULL;
    }
    else//表里不只有一个结点的时候
    {
        Node* cur = L->head;

        //把cur移动到待删除元素的头上
        if (m >= 0)
            for (int i = 1; i <= m; i++)
                cur = cur->next;
        else
            for (int i = -1; i >= m; i--)
                cur = cur->prior;
        
        L->head = cur->next;//把表头接过来先

        ///进行删除时的指针域调整
        cur->prior->next = cur->next;
        cur->next->prior = cur->prior;
        cur->next = NULL;
        cur->prior = NULL;

        ///带出所需的值
        order = cur->order;
        m = cur->data;

        free(cur);
        cur = NULL;
    }
}

void DestroyList(List L)
{
    if(IsEmpty(L)) ;
    else
       do
       {
            Node* temp = L->head;
            L->head = temp->next;
            free(temp);
            temp = NULL;
       } while (!IsEmpty(L));
    free(L);
}
