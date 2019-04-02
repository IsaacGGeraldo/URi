#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// DEFINES ********************************************************************************************************************

#define Max 1010

// DECLARAÇÃO DA STRUCT *******************************************************************************************************


struct pilha
{
    int topo,item[1010];
};

// DECLARAÇÃO DE FUNÇÕES AUXILIARES *******************************************************************************************

void IniciaPilha(struct pilha *AA);                                     //INICIA A PILHA
int PilhaVazia(struct pilha *AA);                                       //VERIFICA DE A PILHA ESTÁ VAZIA
int Push(struct pilha *AA,int valor);                                    //ADICIONA UM ELEMENTO NA PILHA
int Pop(struct pilha *AA);                                              //TIRA UM ELEMENTO DA PILHA
int Mostra(struct pilha *AA);
char *LerExpressao(char *str);
struct pilha *TrataDiamante(char*str);

// FUNÇÂO PRINCIPAL ***********************************************************************************************************
int main()
{
    int aux,diamantes,fecha,i,n=1;
    char* expressao;
    struct pilha *parenteses;
    bool certo=true;
    scanf("%d",&n);
    setbuf(stdin,NULL);
    for(i=1;i<=n;i++)
    {
        expressao= LerExpressao(expressao);
        parenteses=TrataDiamante(expressao);

        /*printf("EM UMA STRING: %s\n",expressao);
        if(!PilhaVazia(parenteses))
        {
            printf("EM UMA PILHA:");
            Mostra(parenteses);
            printf("\n");
        }*/

        fecha=0;diamantes=0;
        do
        {
            if(!PilhaVazia(parenteses))aux=Pop(parenteses);
            else aux=0;
            if(aux== '>')fecha++;
            else if(aux=='<' && fecha)
            {
                fecha--;
                diamantes++;
            }
        } while (!PilhaVazia(parenteses));
        printf("%d\n",diamantes);
    }
    
    return 0;
}

// FUNÇÕES AUXILIARES *********************************************************************************************************

void IniciaPilha(struct pilha *AA)
{
    AA->topo=-1;
}

//-----------------------------------------------------------------------------------------------------------------------------

int PilhaVazia(struct pilha *AA)
{
    if(AA->topo==-1)return 1;
    else return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------

int Push(struct pilha *AA,int valor)
{
    return (AA->item[++(AA->topo)]=valor);
}

//-----------------------------------------------------------------------------------------------------------------------------

int Pop(struct pilha *AA)
{
    int aux;
    aux = AA->item[(AA->topo)--];
    return aux;
}

//-----------------------------------------------------------------------------------------------------------------------------
int Mostra(struct pilha *AA)
{
    int aux;
    struct pilha AAux;
    IniciaPilha(&AAux);
    //system("cls");
    while(!PilhaVazia(AA))
    {
        aux=Pop(AA);
        printf("  %d",aux);
        Push(&AAux,aux);
    }
    while(!PilhaVazia(&AAux))
    {
        aux=Pop(&AAux);
        Push(AA,aux);
    }
    
}

//-----------------------------------------------------------------------------------------------------------------------------
 
char *LerExpressao(char *str)
{
    str = (char *)malloc(0);
    int c,i=0;
    while((c=getchar())!='\n')
    {
        i++;
        str= (char *)realloc(str,i*sizeof(char));
        if(str==NULL)
        {
            printf("MEMORIA INSUFICIENTE.\n");
            exit(1);
        }
        str[i-1]=c;
    }
    str = (char *)realloc(str,(i+1)*sizeof(char));
    if(str==NULL)
    {
        printf("MEMORIA INSUFICIENTE\n");
        exit(1);
    }
    str[i]='\0';
    //printf("%s\n",str);
    return str;
}

//-----------------------------------------------------------------------------------------------------------------------------

struct pilha *TrataDiamante(char*str)
{
    struct pilha *retorno;
    int i=0,c;
    retorno= (struct pilha *)malloc(sizeof(struct pilha));
    IniciaPilha(retorno);
    while(str[i] != '\0')
    {
        c=str[i];
        if(!isdigit(c))
        {
            if(c=='<' || c=='>')Push(retorno,c);
        }
        i++;
    }
    return retorno;
}