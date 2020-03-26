#include<stdio.h>
#include<stdlib.h>
#include"DCLinkedList.h"
#define ERROR printf("STACK OVERFLOW")

void CreateList(List L, int n)
{//��������nûɶ�ã�ֻ��Ϊ�˺�Sq��ͳһ
    L->head = NULL;
    //L->prior = NULL; 
    //�������ͷ���ǰ�һ��ָ���װ�ĸ�����ûɶ�ر��
    //�������ͷ��㣬ֻ��������û��������
}
int getLength(List L)
{
    if (IsEmpty(L)) return 0;//�ձ�
    else
    {
        Node* p = L->head;
        int Length = 1;//�Ȱ���Ԫ����
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
    return (L->head == NULL ); //�Ƿ����ͷ���
}

void InsertElem(List L, int i, int m, int order)
{
    if (IsEmpty(L))     //��LΪ�ձ������
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = m;
        temp->order = order;
        L->head = temp;
        temp->next = temp;
        temp->prior = temp;
    }
    else//��ǿյ�ʱ��
    {
        Node* ins = L->head; //����һ��Nodeָ��ָ��L����Ԫ
        
        for (; i > 1; i--) //��insָ�����ε��������λ��ǰ��
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
    if (L->head->next==L->head) //ֻʣһ������ʱ��
    {
        /*Node* temp = L->head;
        temp->next = NULL;
        L->head = NULL;*/
        
        L->head->next = L->head->prior=NULL;

        ///���������ֵ
        order =L->head->order;
        m = L->head->data;

        free(L->head);
        L->head = NULL;
       
    }
    else//���ﲻֻ��һ������ʱ��
    {
        Node* cur = L->head;
        //Node* pre = L->tail;
        //��������Nodeָ��ָ��L�ı�ͷԪ�أ��ڱ�����ֱ�ָ���ɾ���Ľ�������ǰ�����
        for (int i = 1; i <= m; i++)//��cur�ƶ�����ɾ��Ԫ�ص�ͷ��
        {
           // pre = pre->next;
            cur = cur->next;
        }
        //while (pre->next != cur) pre = pre->next;///��ѭ������һ����ȱ�ݵĵط�
        ///���ɾ����Ԫ�Ļ���preָ��ð���������һ�飬��
        //��һ�������Ǹ�ѭ�������һ��β��㣬�о�����������ͷ�ڵ�����ӡ�

        L->head = cur->next;//�ѱ�ͷ�ӹ�����

        ///����ɾ��ʱ��ָ�������
        cur->prior->next = cur->next;
        cur->next->prior = cur->prior;
        cur->next = NULL;
        cur->prior = NULL;

        ///���������ֵ
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
