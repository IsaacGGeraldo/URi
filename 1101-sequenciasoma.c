//1101
#include <stdio.h>

int main()
{
    int primeiro,segundo,maior,menor,soma=0,cont;
    while(1)
    {
        scanf("%d %d",&primeiro,&segundo);

        if (primeiro<=0 || segundo<=0)break;

        if(primeiro>segundo)
        {
            maior=primeiro;
            menor=segundo;
        }
        else
        {
            menor=primeiro;
            maior=segundo;
        }
        soma=0;
        for(cont=menor;cont<=maior;cont++)
        {
            printf("%d ",cont);
            soma+=cont;
        }
        printf("Sum=%d\n",soma);
    }
    return 0;
}