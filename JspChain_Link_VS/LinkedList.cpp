#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

void CreateList(List L,int n)
{//��������nûɶ�ã�ֻ��Ϊ�˺�Sq��ͳһ
    L->head= NULL;
    L->tail = NULL;
    //L->prior = NULL; 
    //ֻ��ͷ��������Ԫ��㣬
    //�ʴ�ʱ������Ȼ��һ����㣬
    //��ʵ������Ԫ�ظ���Ϊ��
}
int getLength(List L)
{
    if (IsEmpty(L)) return 0;//�ձ�
    else
    {
        Node* p = L->head;
        int Length = 1;//�Ȱ���Ԫ����
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
    return (L->head == NULL&&L->tail==NULL); //�Ƿ����ͷβ���
}

void InsertElem(List L, int i, int m,int order)
{
    if (IsEmpty(L))     //��LΪ�ձ������
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
    else//��ǿյ�ʱ��
    {
        Node* ins = L->head; //����һ��Nodeָ��ָ��L����Ԫ
        //printf("here");
        for (; i > 1; i--) //��insָ�����ε��������λ��ǰ��
        {
            ins = ins->next;
            //printf("there");
        }

        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;

        temp->next = ins->next;
        ins->next = temp;
        if (temp->next == L->head) L->tail = temp;//�����ԭ����β���֮����룬���tail��һ��
        //temp->prior = ins;
        //temp->next->prior = temp;
        //temp->prior->next = temp;

        //free(temp);
        //temp = NULL;
    }
}

void DeleteElem(List L, int &m, int &order)
{

   // if (L->next->next != L->next) //�����в�ֻһ������ʱ��
    if(L->head!=L->tail) //�����в�ֻһ������ʱ��
    {
        Node* cur = L->head;
        Node* pre=L->tail;
        //��������Nodeָ��ָ��L�ı�ͷԪ�أ��ڱ�����ֱ�ָ���ɾ���Ľ�������ǰ�����
        for (int i = 1; i <= m; i++)//��cur�ƶ�����ɾ��Ԫ�ص�ͷ��
        {
            pre = pre->next;
            cur = cur->next;
        }
        //while (pre->next != cur) pre = pre->next;///��ѭ������һ����ȱ�ݵĵط�
        ///���ɾ����Ԫ�Ļ���preָ��ð���������һ�飬��
        //��һ�������Ǹ�ѭ�������һ��β��㣬�о�����������ͷ�ڵ�����ӡ�

        L->head = cur->next;//�ѱ�ͷ�ӹ�����
        L->tail = pre;

        ///����ɾ��ʱ��ָ�������
        pre->next = cur->next;
        cur->next = NULL;

        ///���������ֵ
        order = cur->order;
        m = cur->data;

        free(cur);
        cur = NULL;
    }
    else//ֻʣһ������ʱ��
    {
        Node* temp = L->head;
        temp->next = NULL;
        L->head = NULL;
        L->tail = NULL;

        ///���������ֵ
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
