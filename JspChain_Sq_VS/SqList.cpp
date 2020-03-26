#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

#define ERROR printf("STACK OVERFLOW")

void CreateList(List L ,int n)///����һ��nodeԪ�س���Ϊn�ı�����ʼ���ã����ر�ͷָ��
{
    if (L == NULL) { ERROR; return; }//�����L�ĵ�ַ����ʧ���򱨴�
    L->node = (Node*)malloc(n * sizeof(Node));//��nodeһ���Է����ַ
    if (L->node == NULL) { ERROR; return; }//�����node�ĵ�ַ����ʧ���򱨴�
    L->cur=0;//��ʼ��cur��λ��
    L->Length=0;//��ʼ��L�ĳ���ֵ
}

bool IsEmpty(List L)///����L�Ƿ�Ϊ�ձ�
{
    return (L->Length)?false:true;
}

void InsertElem(List L,int i,int m, int order)///��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��
{
        L->Length += 1;
        for (int j = L->Length-1 ; j > i; j--)//��i֮���Ԫ��ȫ������ƶ�
        {
            L->node[j].data = L->node[j - 1].data;
            L->node[j].order = L->node[j - 1].order;
        }

        L->node[i].data=m;//��i����¼���µ�Ԫ�ص�ֵ
        L->node[i].order =order ;

        //printf("insert order=%d\ninsert data=%d\n", L->node[i].order,L->node[i].data);
}

void DeleteElem(List L, int &m,int &order)
///�ӱ�L��ɾ����cur�������ĵ�m��Ԫ�أ�������Ԫ�ص�m����ֵ��mPtrд��ԭm�ĵ�ַ�ϣ�
///����curָ��m����һ��Ԫ��λ�ô���������������del������ͬ�ĵط���
///��order������ɾ����Ԫ�صı��
{
        for (int i = 0; i < m; i++)///�ζ�cur����m��Ԫ�ص�ͷ��
        {
            L->cur++;
            if (L->cur == L->Length) L->cur = 0;///������βʱ�ص���ͷ
            //!!!!!!�����д����������ܸ�L.Length,���б�������������
            ///���Ի��ǻع��Ч���ƶ�һ�����İ취��~~
            //if(L->node[L->cur].is_inChain==false) i--;///����������ѳ�����Ԫ�أ�����α������㣬��i�˻�һ��
            //while (L->node[L->cur].is_inChain == false) L->cur++;
        }

    ///���������ֵ
    m = L->node[L->cur].data;
    order = L->node[L->cur].order;

    L->Length -= 1;
    for (int j = L->cur; j < L->Length; j++)//��cur���Ԫ����ǰ�ƶ�
    {
        L->node[j].data = L->node[j + 1].data;
        L->node[j].order = L->node[j + 1].order;
    }
    if (L->cur == L->Length) 
        L->cur = 0; //���ɾ�����Ǳ�β��Ԫ�أ��ǵð�cur�Ƶ�ͷ������˳ʱ�����һ��Ԫ�ؿ�ʼת��
}

void DestroyList(List L)
{
    free(L->node);
    L->node = NULL;
    free(L);
    L = NULL;
}
