#include <stdio.h>

int main()
{
    int i,j,inicio=7,fim=5;
    for(i=1;i<=9;i++)
    {
        if(i%2==1)
        {
            for(j=inicio;j>=fim;j--)
            {
                printf("I=%d J=%d\n",i,j);
            }
            inicio+=2;
            fim+=2;
        }
    }

    return 0;
}