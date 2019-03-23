#include <stdio.h>

int main()
{
    int QuantidadeNumeros=0,Impressos=1,Anterior=0,Atual=1,aux;
    while(QuantidadeNumeros<1 || QuantidadeNumeros>45)
    {
        scanf("%d",&QuantidadeNumeros);
    }
    
    while(Impressos<=QuantidadeNumeros)
    {
        if (Impressos==1) 
        {
            //printf(" ");
            printf("%d",Anterior);
            Impressos++;
        }
        else if (Impressos==2||Impressos==3) 
        {
            printf(" ");
            printf("%d",Atual);
            Anterior=Atual;
            Impressos++;
        }
        else
        {
            //printf(" ");
            aux=Atual;
            Atual=Atual+Anterior;
            Anterior=aux;
            printf(" %d",Atual);
            Impressos++;
        }
    }
    printf("\n");

    return 0;
}