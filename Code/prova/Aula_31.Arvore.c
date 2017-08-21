#include "stdio.h"
#include "stdlib.h"

struct No* RemoverFilhoUnico(struct No *Pai);
struct No* RemoverNoFolha(struct No *Folha);

struct No
{
    int Id;
    struct No *Esquerda;
    struct No *Direita;
};

struct No *Atual = (struct No*) NULL;
struct No *Ultimo = (struct No*) NULL;

struct No* AdicionarNo(struct No *Raiz, int Id)
{
    if (Raiz == (struct No*) NULL)
    {
        Raiz = (struct No*) malloc(sizeof(struct No));
        Raiz-> Id = Id;
        Raiz-> Esquerda = (struct No*) NULL;
        Raiz-> Direita = (struct No*) NULL;
        return Raiz;
    }

    Atual = Raiz;
    while(Atual != NULL)
    {
        Ultimo = Atual;

        if (Id < Atual-> Id)
            Atual = Atual-> Esquerda;
        else if (Id > Atual-> Id)
            Atual = Atual-> Direita;
        else
            return Raiz;
    }

    Atual = Ultimo;
    if (Id < Atual-> Id)
    {
        Atual-> Esquerda = (struct No*) malloc(sizeof(struct No));
        Atual = Atual-> Esquerda;
    }
    else
    {
        Atual-> Direita = (struct No*) malloc(sizeof(struct No));
        Atual = Atual-> Direita;
    }

    Atual-> Id = Id;
    Atual-> Esquerda = (struct No*) NULL;
    Atual-> Direita = (struct No*) NULL;
    return Raiz;
}

struct No* AdicionarNoComRecursividade(struct No *Raiz, int Id)
{
    if (Raiz == (struct No*) NULL)
    {
        Raiz = (struct No*) malloc(sizeof(struct No));
        Raiz-> Id = Id;
        Raiz-> Esquerda = (struct No*) NULL;
        Raiz-> Direita = (struct No*) NULL;
        return Raiz;
    }

    if (Id < Raiz-> Id)
        Raiz-> Esquerda = AdicionarNoComRecursividade(Raiz-> Esquerda, Id);
    else if (Id > Raiz-> Id)
        Raiz-> Direita = AdicionarNoComRecursividade(Raiz-> Direita, Id);

    return Raiz;
}

struct No* BuscarNo(struct No *Raiz, int Id)
{
    while(Raiz != (struct No*) NULL)
    {
        if (Id > Raiz-> Id)
            Raiz = Raiz-> Direita;
        else if (Id < Raiz-> Id)
            Raiz = Raiz-> Esquerda;
        else
            return Raiz;
    }

    return (struct No*) NULL;
}

struct No* BuscarNoComRecursividade(struct No *Raiz, int Id)
{
    if (Raiz == (struct No*) NULL)
        return Raiz;

    if (Raiz-> Id == Id)
        return Raiz;

    if (Id > Raiz-> Id)
        return BuscarNoComRecursividade(Raiz-> Direita, Id);
    else if (Id < Raiz-> Id)
        return BuscarNoComRecursividade(Raiz-> Esquerda, Id);
}

void PreOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    printf("%d ", NoAtual->Id );
    PreOrdem(NoAtual-> Esquerda);
    PreOrdem(NoAtual-> Direita);
}

void PosOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    PosOrdem(NoAtual-> Esquerda);
    PosOrdem(NoAtual-> Direita);
    printf("%d ", NoAtual->Id );
}

void EmOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    EmOrdem(NoAtual-> Esquerda);
    printf("%d ", NoAtual->Id );
    EmOrdem(NoAtual-> Direita);
}

void EmOrdemInversa(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    EmOrdemInversa(NoAtual-> Direita);
    printf("%d ", NoAtual->Id );
    EmOrdemInversa(NoAtual-> Esquerda);
}

int IsNull(struct No *Raiz)
{
	return (Raiz == (struct No*)NULL);
}

struct No* BuscaMenorNo(struct No *Raiz)
{
	if(IsNull(Raiz))
		return (struct No*) NULL;

	if(IsNull(Raiz-> Esquerda))
		return Raiz;
	else
		return BuscaMenorNo(Raiz-> Esquerda);
}

void RemoverNo(struct No **Raiz, int Id)
{
	struct No *Auxiliar;

	if (IsNull(*Raiz))
	   return;

	if(Id < (*Raiz)-> Id)
	{
		RemoverNo(&((*Raiz)-> Esquerda), Id);
		return;
	}

	if(Id > (*Raiz)-> Id)
	{
		RemoverNo(&((*Raiz)-> Direita), Id);
		return;
	}

	if(!IsNull((*Raiz)-> Esquerda) && !IsNull((*Raiz)-> Direita))
	{
		Auxiliar = BuscaMenorNo((*Raiz)-> Direita);
		(*Raiz)-> Id = (Auxiliar-> Id);
		RemoverNo(&(*Raiz)-> Direita, (*Raiz)-> Id);
	}
	else
	{
		Auxiliar = *Raiz;
		if(IsNull((*Raiz)-> Esquerda))
			*Raiz = (*Raiz)-> Direita;
		else
			*Raiz = (*Raiz)-> Esquerda;
		free(Auxiliar);
	}
}
