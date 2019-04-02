#include <stdio.h>

int main()
{
    int i,j;
    for(i=0;i<=20;i+=2)
    {
        for(j=1;j<=3;j++)
        {
            if(i%10)printf("I=%.1f J=%.1f\n",i/10.0,j+(i/10.0));
            else printf("I=%.0f J=%.0f\n",i/10.0,j+(i/10.0));
        }
    }
    return 0;
}