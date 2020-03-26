#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"Josephus_Sq.h"

int main()
{
    freopen("out.txt", "w", stdout);
    for (int z = 0; z <= 10; z++) {
        LARGE_INTEGER startTick, endTick, Tick_Per_Sec;
        QueryPerformanceFrequency(&Tick_Per_Sec);

        int n, m;
        List L = (LIST*)malloc(sizeof(LIST));

#if DEBUG
        // 例程：
        m = 20;
        n = 7;
        CreateList(L, n);///生成一个总长为n的表L
        L->Length = n;
        L->node[0].data = 3; L->node[0].order = 1;
        L->node[1].data = 1;  L->node[1].order = 2;
        L->node[2].data = 7; L->node[2].order = 3;
        L->node[3].data = 2; L->node[3].order = 4;
        L->node[4].data = 4; L->node[4].order = 5;
        L->node[5].data = 8; L->node[5].order = 6;
        L->node[6].data = 4; L->node[6].order = 7;
        //输出为：6 1 4 7 2 3 5

#else
        srand(time(NULL));
        while (0 == (n = rand() % 100));
#endif // DEBUG
        CreateList(L, n);///生成一个总长为n的表L
        Randomize(n, m, L);


        int* popOrder = (int*)malloc(n * sizeof(int));

        QueryPerformanceCounter(&startTick);
        Josephus(m, L, popOrder);
        QueryPerformanceCounter(&endTick);

        DestroyList(L);
#if DEBUG
        for (int i = 0; i < n; i++) printf("%d ", popOrder[i]);
        printf("%s %lf %s", "\nrunning time:", (double)(endTick.QuadPart - startTick.QuadPart) / Tick_Per_Sec.QuadPart, "s\n");
        system("pause");
#else
        printf("%d\t%lf\n", n, (double)(endTick.QuadPart - startTick.QuadPart) / Tick_Per_Sec.QuadPart);
#endif /*DEBUG*/ 
    }
    fclose(stdout);
    return 0;
}
