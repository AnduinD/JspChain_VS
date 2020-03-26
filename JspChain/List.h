#pragma once
#define DEBUG 0     //0���Ѷ�������������ļ��Լ�¼��1���ڿ���̨����
#define LINKED_LIST 1   //�ײ��õ�ѭ������ʵ��
#define SQ_LIST 0       //�ײ���˳���ʵ��

#if LINKED_LIST
typedef struct Node {
    int order;//ÿ���˵ı��
    int data;//ÿ�������е�����ֵ
    struct Node* next;//ָ����һԪ�ص�ָ��
    //struct Node* prior;//ָ��ǰһԪ�ص�ָ��
}Node;

typedef struct LIST {
    //��ѭ��������ͷ��β����ָ���װһ��
    Node* head;
    Node* tail;
}*List;
#endif //LINKED_LIST

#if SQ_LIST
typedef struct Node {
    int data;///����ֵ
    int order;///��ţ��������Ԫ�ص�ɾ�����ı䣩
}Node;
typedef struct LIST {
    Node* node;///����֮���������Ϊ�ṹ������
    int cur;///ָ��ǰԪ�ص�ָ��
    int Length;///��¼��
}LIST, * List;
///���������Ƚ����⣬�����˳���ʵ������Ҳ��̫һ��233
#endif //SQ_LIST

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
