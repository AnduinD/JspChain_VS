#pragma once
typedef struct Node{
    int data;///����ֵ
    int order;///��ţ��������Ԫ�ص�ɾ�����ı䣩
}Node;
typedef struct LIST{
    Node* node;///����֮���������Ϊ�ṹ������
    int cur;///ָ��ǰԪ�ص�ָ��
    int Length;///��¼��
}LIST,*List;
///���������Ƚ����⣬�����˳���ʵ������Ҳ��̫һ��233

void CreateList(List L,int n);///����һ��nodeԪ�س���Ϊn�ı�����ʼ���ã����ر�ͷָ��

bool IsEmpty(List L);///����L�Ƿ�Ϊ�ձ�

void InsertElem(List L,int i,int m,int order);///��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��

void DeleteElem(List L, int &mPtr,int &order);
///�ӱ�L��ɾ����m��Ԫ�أ�������Ԫ�ص�m����ֵ��mPtrд��ԭm�ĵ�ַ�ϣ�
///������ͷָ���ƶ���m����һ��Ԫ��λ�ô���������������del������ͬ�ĵط���
///��order������ɾ����Ԫ�صı��
//#endif /*SqList*/

void DestroyList(List L);///���ٱ�L