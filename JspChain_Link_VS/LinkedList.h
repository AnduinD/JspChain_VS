#pragma once
typedef struct Node{
    int order;//ÿ���˵ı��
    int data;//ÿ�������е�����ֵ
    struct Node* next;//ָ����һԪ�ص�ָ��
    //struct Node* prior;//ָ��ǰһԪ�ص�ָ��
}Node/*,LIST,*List*/;

typedef struct LIST {
    //��ѭ��������ͷ��β����ָ���װһ��
    Node* head;
    Node* tail;
}*List;

void CreateList(List L,int n);//����һ���յĻ������ر�ͷָ��

int getLength(List L);//���ر�L�ĳ���

bool IsEmpty(List L);//����L�Ƿ�Ϊ�ձ�

void InsertElem(List L,int i,int m,int order);//��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��

void DeleteElem(List L, int &m,int &order);
//�ӱ�L��ɾ����m��Ԫ�أ�������Ԫ�ص�m����ֵ��mPtrд��ԭm�ĵ�ַ�ϣ�
//������ͷָ���ƶ���m����һ��Ԫ��λ�ô���������������del������ͬ�ĵط���
//��order������ɾ����Ԫ�صı��

void DestroyList(List L);//��������L
//#endif /*LinkedList*/
