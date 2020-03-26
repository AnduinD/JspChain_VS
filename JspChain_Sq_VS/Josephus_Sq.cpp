#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Josephus_Sq.h"

void Randomize(int n,int &m, List L)///随机初始化函数
{
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++)
    {
        while(0==(m=((rand()%2==0)?1:-1)*rand()));///生成正负随机的数m作为下一个要新建的元素的密码
        //注意：按题目要求，从自身开始报1，报到m为止，
        //所以m=+-1时cur没有移动，且知m可正可负，但不可为零！！！
        InsertElem(L,i,m,i+1);///在L表中的第i个元素后插入密码值为m的新元素
    }
    while (0 == (m=(rand()%2?1:-1)*rand()));///随机生成初始密码
    printf("%s","Inserting Over\n"); 
    printf("n = %d\n", n);
    printf("press any key to start\n");

    getchar();
}

void Josephus(int m,List L,int *popOrder)///用顺序表模拟约瑟夫环的函数
{
    int i=0;
    while(!IsEmpty(L))
    {
        //if (m == 0) { printf("要求从1开始报数！\n"); return; }
        if (m > 0)//顺时针转的时候
            m=m% L->Length-1;//这个减1是因为从自己报1开始
        else//逆时针转的时候
            m = m% L->Length+1;//这个加1是因为从自己报1开始
        
        DeleteElem(L,m,popOrder[i++]);///从表L中删除第m个元素，
                                          ///并将表头移动到m的下一个元素位置处(删除时移动表头很关键！！！)
                                          ///带回第m个元素的密码值作为下次启动的密码
                                          ///带回其编号，并存入popOrder中
        //printf("pop order=%d\n",popOrder[i]);
        
    }
}

