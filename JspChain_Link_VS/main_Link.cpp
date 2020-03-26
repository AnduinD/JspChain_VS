#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"Josephus_Link.h"

int main()
{
    freopen("out.txt", "w", stdout);
    for (int z = 0; z <= 10; z++) 
    {
        LARGE_INTEGER startTick, endTick, Tick_Per_Sec;
        QueryPerformanceFrequency(&Tick_Per_Sec);

        int n, m;
        List L = (LIST*)malloc(sizeof(LIST));

#if DEBUG
        m = 20, n = 7;
#else
        srand(z*time(NULL));
        while(0==(n = rand() % 1000000)) ;
#endif // DEBUG
        CreateList(L,n);
        Randomize(n, m, L);

        int* popOrder = (int*)malloc(n * sizeof(int));

        QueryPerformanceCounter(&startTick);
        Josephus(m, L, popOrder);
        QueryPerformanceCounter(&endTick);


        DestroyList(L);
#if DEBUG
        for(int i=0;i<n;i++) printf("%d ",popOrder[i]);
        printf("%s %lf %s", "\nrunning time:", (double)(endTick.QuadPart - startTick.QuadPart) / Tick_Per_Sec.QuadPart, "s\n");
        system("pause");
#else
        printf("%d\t%lf\n", n, (double)(endTick.QuadPart - startTick.QuadPart) / Tick_Per_Sec.QuadPart);
#endif /*DEBUG*/ 
     }
    fclose(stdout);
    return 0;
}
