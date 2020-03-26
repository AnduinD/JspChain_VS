#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

#define ERROR printf("STACK OVERFLOW")

void CreateList(List L ,int n)///生成一个node元素长度为n的表，并初始化好，返回表头指针
{
    if (L == NULL) { ERROR; return; }//如果给L的地址分派失败则报错
    L->node = (Node*)malloc(n * sizeof(Node));//给node一次性分配地址
    if (L->node == NULL) { ERROR; return; }//如果给node的地址分派失败则报错
    L->cur=0;//初始化cur的位置
    L->Length=0;//初始化L的长度值
}

bool IsEmpty(List L)///检测表L是否为空表
{
    return (L->Length)?false:true;
}

void InsertElem(List L,int i,int m, int order)///在L表中的第i个元素后插入密码值为m的新元素
{
        L->Length += 1;
        for (int j = L->Length-1 ; j > i; j--)//把i之后的元素全部向后移动
        {
            L->node[j].data = L->node[j - 1].data;
            L->node[j].order = L->node[j - 1].order;
        }

        L->node[i].data=m;//在i后面录入新的元素的值
        L->node[i].order =order ;

        //printf("insert order=%d\ninsert data=%d\n", L->node[i].order,L->node[i].data);
}

void DeleteElem(List L, int &m,int &order)
///从表L中删除从cur往后数的第m个元素，并将该元素的m密码值用mPtr写到原m的地址上，
///并将cur指向m的下一个元素位置处（这是与正常的del函数不同的地方）
///用order带回所删除的元素的编号
{
        for (int i = 0; i < m; i++)///游动cur到第m个元素的头上
        {
            L->cur++;
            if (L->cur == L->Length) L->cur = 0;///超出队尾时回到队头
            //!!!!!!这里有错！！！！不能改L.Length,但有遍历不到！！！
            ///所以还是回归低效的移动一条数的办法吧~~
            //if(L->node[L->cur].is_inChain==false) i--;///如果遍历到已出环的元素，则这次遍历不算，把i退回一格
            //while (L->node[L->cur].is_inChain == false) L->cur++;
        }

    ///带出所需的值
    m = L->node[L->cur].data;
    order = L->node[L->cur].order;

    L->Length -= 1;
    for (int j = L->cur; j < L->Length; j++)//把cur后的元素往前移动
    {
        L->node[j].data = L->node[j + 1].data;
        L->node[j].order = L->node[j + 1].order;
    }
    if (L->cur == L->Length) 
        L->cur = 0; //如果删除的是表尾的元素，记得把cur移到头（从它顺时针的下一个元素开始转）
}

void DestroyList(List L)
{
    free(L->node);
    L->node = NULL;
    free(L);
    L = NULL;
}
