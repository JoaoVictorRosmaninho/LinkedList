#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
	int num;
	struct node *prox;
} NODE;

typedef NODE* Lista;

//cabeçalhos
void Inic(NODE **lista);	
int add(NODE **lista, int num);
NODE *createnode(int num);
void Display(NODE *lista);
int sort(NODE *lista);
int pop(NODE *lista, int pos);
int Remove(NODE *lista, int valor);
int clear(NODE **lista);
void Mensagem(const char *msg, int cod_err);

int main(void)
{
    Lista lista;
    Inic(&lista);
    add(&lista, 2); 
    add(&lista, 7);
    add(&lista, 5);
    add(&lista, 3);
    add(&lista, 17);
    Display(lista);
    sort(lista);
    Display(lista);
    pop(lista, 2);
    Display(lista);
    Remove(lista, 5);
    Display(lista);
    clear(&lista);
    Display(lista);	
    return 0;
}

//inicia a lista;
void Inic(NODE **lista)
{
	*lista = NULL;
}
//adiciona um valor na ultima posicao;
int add(NODE **lista, int num)
{
	NODE *tmp, *tmp_lista = *lista;
	if(*lista == NULL)
		*lista = createnode(num);	
	else
	{
		tmp = (*lista)->prox;
		while(tmp != NULL) 
			{
				tmp_lista = tmp;
				tmp = tmp->prox;
			}
		tmp = createnode(num);
		tmp_lista->prox = tmp;
	}
	return 1;
}
//criação do nó
NODE *createnode(int num)
{
	NODE *newNode;
	if((newNode = (NODE *) malloc(sizeof(NODE))) == NULL) Mensagem("Erro ao criar Nó, memória insuficiente", 1);
	newNode->num = num;
	newNode->prox = NULL;
	return newNode;
}

//exibe a lista;
void Display(NODE *lista)
{
	if(lista == NULL) Mensagem("Lista Vazia", 3);
	while(lista != NULL)
	{
		printf("%d ", lista->num);
		lista = lista->prox;
	}
	putc('\n', stdout);
}

//Ordena a lista
int sort(NODE *lista)
{
	int aux_num;
	NODE *aux = lista;
	while(aux != NULL && aux->prox != NULL)
	{
		if(aux->num < aux->prox->num)
			aux = aux->prox;
		else
		{
			aux_num = aux->prox->num;
			aux->prox->num = aux->num;
			aux->num = aux_num;
			aux = lista;
		}
	} 

	return 1;
}

//remove um valor N presente no indice I
int pop(NODE *lista, int pos)
{
	int cont = 1;
	NODE *tmp;
	while(lista != NULL)
	{
		if(cont == pos)
		{
			tmp->prox = lista->prox;
			free(lista);
			break;
		}
		tmp = lista;
		lista = lista->prox;
		cont++;
	}
	return 1;
}

//remove a ultima ocorrência de um valor n; 
int Remove(NODE *lista, int valor)
{
	NODE *tmp;
	while(lista != NULL)
	{
		if(lista->num == valor)
		{
			tmp->prox = lista->prox;
			free(lista);
		}
		tmp = lista;
		lista = lista->prox;
	}
	return 1;
}

//limpa toda a lista;
int clear(NODE **lista)
{
	NODE *tmp;
	while(*lista != NULL)
	{
		tmp = (*lista)->prox;
		free(*lista);
		*lista = tmp;
	}
	*lista = NULL;
	return 1;
}

void Mensagem(const char *msg, int cod_err)
{
	puts(msg);		
	exit(cod_err);
}
