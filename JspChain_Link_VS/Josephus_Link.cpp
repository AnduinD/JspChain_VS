#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Josephus_Link.h"

void Randomize(int n,int &m, List L)///�����ʼ������
{
#if DEBUG
    printf("input the m:");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &m);
        InsertElem(L, i, m, i + 1);
    }
    m = 20;
#else
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++)
    {
        while (0 == (m = ((rand() % 2 == 0) ? 1 : -1) * (rand()%51))) ;///���������������m��Ϊ��һ��Ҫ�½���Ԫ�ص�����
        //ע�⣺����ĿҪ�󣬴�����ʼ��1������mΪֹ��
        //����m=+-1ʱcurû���ƶ�����֪m�����ɸ���������Ϊ�㣡����
        InsertElem(L,i,m,i+1);///��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��
    }
    while (0 == (m = (rand() % 2 ? 1 : -1) * (rand() % 51))) ;///������ɳ�ʼ����
#endif /*DEBUG*/

#if DEBUG
    printf("%s", "Inserting Over\n");
    printf("n = %d\n", n);
    printf("press any key to start\n");
    getchar();
#endif /*DEBUG*/
}

void Josephus(int m,List L,int *popOrder)///��˫ѭ������ģ��Լɪ�򻷵ĺ���
{
    int i=0;
    while(!IsEmpty(L))
    {
        if (m > 0)//˳ʱ��ת��ʱ��
            m = m % getLength(L) - 1;//�����1����Ϊ���Լ���1��ʼ
        else//��ʱ��ת��ʱ��
            m = m % getLength(L) + 1;//�����1����Ϊ���Լ���1��ʼ
        DeleteElem(L, m, popOrder[i++]);///�ӱ�L��ɾ����m��Ԫ�أ�
                                          ///������ͷ�ƶ���m����һ��Ԫ��λ�ô�(ɾ��ʱ�ƶ���ͷ�ܹؼ�������)
                                          ///���ص�m��Ԫ�ص�����ֵ��Ϊ�´�����������
                                          ///�������ţ�������popOrder��
    }
}

