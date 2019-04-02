//1132
#include <stdio.h>

int main()
{
    int primeiro,segundo,maior,menor,soma=0,cont;

    scanf("%d",&primeiro);
    scanf("%d",&segundo);

    //if (primeiro<=0 || segundo<=0)break;

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
        //printf("%d ",cont);
        if(cont%13!=0)soma+=cont;
    }
    printf("%d\n",soma);
    return 0;
}