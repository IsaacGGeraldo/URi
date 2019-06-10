#include <stdio.h>

main()
{
    int t1,t2,t3,t4,resultado;
    scanf("%d%*c%d%*c%d%*c%d", &t1, &t2 , &t3, &t4);
    printf("%d\n", (t1+t2+t3+t4-3));
}