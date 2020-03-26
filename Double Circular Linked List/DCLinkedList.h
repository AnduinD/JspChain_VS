#pragma once
#define DEBUG 1     //0���Ѷ�������������ļ��Լ�¼��1���ڿ���̨����
//#define LINKED_LIST 1   //�ײ��õ�ѭ������ʵ��
//#define SQ_LIST 0       //�ײ���˳���ʵ��

//#if LINKED_LIST

//��˫��ѭ������ʵ��
typedef struct Node {
    int order;//ÿ���˵ı��
    int data;//ÿ�������е�����ֵ
    struct Node* next;//ָ����һԪ�ص�ָ��
    struct Node* prior;//ָ��ǰһԪ�ص�ָ��
}Node;

typedef struct LIST {
    //˫ѭ��������ͷָ���װһ��
    Node* head;
}*List;
//#endif //LINKED_LIST

void CreateList(List L, int n);///����һ��nodeԪ�س���Ϊn�ı�����ʼ���ã����ر�ͷָ��

int getLength(List L);//���ر�L�ĳ���

bool IsEmpty(List L);///����L�Ƿ�Ϊ�ձ�

void InsertElem(List L, int i, int m, int order);///��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��

void DeleteElem(List L, int& mPtr, int& order);
///�ӱ�L��ɾ����m��Ԫ�أ�������Ԫ�ص�m����ֵ��mPtrд��ԭm�ĵ�ַ�ϣ�
///������ͷָ���ƶ���m����һ��Ԫ��λ�ô���������������del������ͬ�ĵط���
///��order������ɾ����Ԫ�صı��
//#endif /*SqList*/

void DestroyList(List L);///���ٱ�L
