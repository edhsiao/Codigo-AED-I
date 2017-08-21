#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

typedef struct Pilha
{
    int vet[MAX];
    int topo;
} Pilha;

Pilha pi1,pi2,pi3;

int aux;
int erro;
void inicializarPilhas(Pilha *p,int disk)
{
    int i,total=disk;

    pi1.topo = disk;
    pi2.topo=0;
    pi3.topo=0;
    for(i=0; i<disk; i++)
    {
        pi1.vet[i]=total;
        total--;
        pi2.vet[i]=0;
        pi3.vet[i]=0;
    }


}


void Empilhar(Pilha* p, int i)
{
    p->vet[p->topo]= i;
    p->topo++;
}

int Desempilhar(Pilha* p)
{

    p->topo--;
    p->vet[p->topo];
    return p->vet[p->topo];
}

int temErro(Pilha* p)
{
    int i;
    for(i=p->topo-1; i>=0; i--)
    {
        if(p->vet[i] < aux-1 || p->vet[p->topo]< aux-1 && p->vet[i]< aux )
        {
            return 1;
            exit(0);
        }
    }
}
void ExibirPilhas(struct Pilha *p,int disk)
{
    int i;
    for(i=disk-1; i>=0; i--)
    {
        pi1.vet[i];
    }
    for(i=disk-1; i>=0; i--)
    {
        pi2.vet[i];
    }
    for(i=disk-1; i>=0; i--)
    {
        pi3.vet[i];
        printf("\n%d\t%d\t%d",pi1.vet[i],pi2.vet[i],pi3.vet[i]);
    }
    printf("\n(A)\t(B)\t(C)\n");
}

int SelectEmpilhar(struct Pilha **p, int num,int disk)
{
    if(num ==1)
    {
        erro=temErro(&pi1);
        Empilhar(&pi1,aux);
        ExibirPilhas(&pi1,disk);
    }
    else
    {
        if(num ==2)
        {
            erro=temErro(&pi2);
            Empilhar(&pi2,aux);
            ExibirPilhas(&pi3,disk);
        }
        else
        {
            if(num ==3)
            {
                erro=temErro(&pi3);
                Empilhar(&pi3,aux);
                ExibirPilhas(&pi3,disk);
            }
        }
    }
    return erro;
}
int SelectDesempilhar(int num)
{
    if(num == 1)
    {
        aux = Desempilhar(&pi1);
    }
    else
    {
        if(num ==2)
        {
            aux = Desempilhar(&pi2);
        }
        else
        {
            if(num ==3)
            {
                aux = Desempilhar(&pi3);
            }
        }
    }
}


void jogar(struct Pilha *p,int disk ,int move)
{
    int i=0,origem,destino;
    ExibirPilhas(&pi1,disk);

    while(i < move)
    {
        scanf("%d %d",&origem,&destino);
        SelectDesempilhar(origem);
        SelectEmpilhar(&p,destino,disk);

        i++;
    }
    if(move<(pow(2,disk-1)))
        printf("Unfinished %d %d\n",disk,move);
    else
    {
        if (erro==0)
            printf("Solved %d %d\n",disk,move);
        else
            printf("Wrong move %d %d\n",disk,move);
    }
}




int main()
{
    int teste,disk, move,i ;

    struct Pilha p;



    scanf("%d",&teste);
    for (i=0; i<teste; i++)
    {
        scanf("%d %d",&disk,&move);
        inicializarPilhas(&p,disk);
        jogar(&p,disk,move);

    }



}



