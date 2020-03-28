#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Josephus.h"

inline void mRandomize(int& m)
{
    while (0 == (m = ((rand() % 2 == 0) ? 1 : -1) * ((double)rand()/RAND_MAX)*m_MAX));
}

void Randomize(int n, int& m, List L)///�����ʼ������
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
    for (int i = 0; i < n; i++)
    {
        mRandomize(m);///���������������m��Ϊ��һ��Ҫ�½���Ԫ�ص�����
        //ע�⣺����ĿҪ�󣬴�����ʼ��1������mΪֹ��
        //����m=+-1ʱcurû���ƶ�����֪m�����ɸ���������Ϊ�㣡����
        InsertElem(L, i, m, i + 1);///��L���еĵ�i��Ԫ�غ��������ֵΪm����Ԫ��
    }
    mRandomize(m);///������ɳ�ʼ����
#endif /*DEBUG*/

#if DEBUG
    printf("%s", "Inserting Over\n");
    printf("n = %d\n", n);
    printf("press any key to start\n");
    getchar();
#endif /*DEBUG*/
}

void Josephus(int m, List L, int* popOrder)///��˫ѭ������ģ��Լɪ�򻷵ĺ���
{
    int i = 0;
    while (!IsEmpty(L))
    {
            m %= getLength(L);//ģ��һȦ֮��
            m = (m-1) >(getLength(L)-m+1) ? (m - getLength(L)-1) : (m-1) ;//�Ƚ���ת�ͷ�ת�ľ���

        DeleteElem(L, m, popOrder[i++]);///�ӱ�L��ɾ����m��Ԫ�أ�
                                          ///������ͷ�ƶ���m����һ��Ԫ��λ�ô�(ɾ��ʱ�ƶ���ͷ�ܹؼ�������)
                                          ///���ص�m��Ԫ�ص�����ֵ��Ϊ�´�����������
                                          ///�������ţ�������popOrder��
    }
}

