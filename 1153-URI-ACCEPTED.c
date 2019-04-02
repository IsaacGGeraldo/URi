#include <stdio.h>

int main()
{
    int num=0,soma;
    scanf("%d",&num);

    while(num<=0 || num>13)scanf("%d",&num);
    soma=num;
    for(num=num-1;num>0;num--)
    {
        soma*=num;
    }
    printf("%d\n",soma);
}