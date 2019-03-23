#include <stdio.h>
#include <stdbool.h>

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

// FUNÇÂO PRINCIPAL ***********************************************************************************************************
int main()
{
    while(1)
    {
        struct pilha Entrada,Saida,Estacao;
        IniciaPilha(&Entrada);
        IniciaPilha(&Saida);
        IniciaPilha(&Estacao);
        int n,cont,aux;
        scanf("%d",&n);
        if(n==0)break;
        else
        {
            while(1)
            {
                for(cont=0;cont<n;cont++)
                {
                    scanf("%d",&aux);
                    if(aux==0)
                    {
                        printf("\n");
                        break;
                    }
                    Push(&Entrada,aux);
                }
                if(aux) //VERIFICA SE A PILHA ESTAR EM ORDEM
                {
                    int topoentrada,topoestacao,proxsaida=n;
                    bool certo=true;

                    //printf("\nENTRADA:");Mostra(&Entrada);printf("\n");printf("SAIDA:");Mostra(&Saida);printf("\n");

                    while(proxsaida && certo)
                    {
                        if(!PilhaVazia(&Entrada))topoentrada=Pop(&Entrada);
                        else topoentrada=0;

                        if(!PilhaVazia(&Estacao))topoestacao=Pop(&Estacao);
                        else topoestacao=0;
                        
                        //printf("ENTRADA:%d ESTACAO:%d\n",topoentrada,topoestacao);

                        if (topoentrada == proxsaida)
                        {
                            Push(&Saida,topoentrada);
                            if(topoestacao) Push(&Estacao,topoestacao);
                            proxsaida--;
                        }
                        else if(topoestacao==proxsaida)
                        {
                            Push(&Saida,topoestacao);
                            if(topoentrada) Push(&Entrada,topoentrada);
                            proxsaida--;
                        }
                        else if(topoentrada)
                        {
                            if(topoestacao) Push(&Estacao,topoestacao);
                            Push(&Estacao,topoentrada);
                        }
                        else if(!topoestacao) certo = false;

                        //printf("\nENTRADA:");Mostra(&Entrada);printf("\n");printf("ESTAÇÂO:");Mostra(&Estacao);printf("\n");printf("SAIDA:");Mostra(&Saida);printf("\n");
                    }

                    //printf("\nENTRADA:");Mostra(&Entrada);printf("\n");printf("SAIDA:");Mostra(&Saida);printf("\n");

                    if(certo==true)printf("Yes\n");
                    else printf("No\n");
                    IniciaPilha(&Entrada);
                    IniciaPilha(&Saida);
                    IniciaPilha(&Estacao);
                }
                else break;
            }
        }
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