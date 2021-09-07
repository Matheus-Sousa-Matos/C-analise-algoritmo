//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tDado {
	int codigo;
	char descricao[30];
};

struct tNo {
	struct tNo *esq;	
	struct tDado dado;
	struct tNo *dir;	
};

int menu(void); 
void inicializar(struct tNo**);
void incluir(struct tNo **, struct tNo*);
void emordem(struct tNo *);
void preordem(struct tNo *);
void posordem(struct tNo *);
struct tNo *consultar(struct tNo*, int);
void destruir(struct tNo*);
int grau(struct tNo*);
struct tNo *menor(struct tNo*);
int excluir(struct tNo**, int);

int main(void) { 
	int op, codigo;
	char descricao[30];
	struct tNo *p, *arvore;	

	inicializar(&arvore);
	do { 
		op = menu(); 
		switch (op) { 
			case 1:
                printf("\n\n*** Inclusao ***\n\n");
                printf("Digite o codigo do produto: ");
                fflush(stdin);
				scanf("%d", &codigo);
                printf("Digite a descricao do produto: ");
                fflush(stdin);
				gets(descricao);
                p = malloc(sizeof(struct tNo));
                p->dado.codigo = codigo;
                strcpy(p->dado.descricao,descricao);
                incluir(&arvore, p);
				break; 
			case 2: 
				printf("\n\n*** Listagem em-ordem ***\n\n"); 
				emordem(arvore);
				break; 
			case 3:
				printf("\n\n*** Listagem pre-ordem ***\n\n"); 
				preordem(arvore);
				break;
			case 4:
				printf("\n\n*** Listagem pos-ordem ***\n\n"); 
				posordem(arvore);
				break;	
			case 5: 
				printf("\n\n*** Consulta ***\n\n");
                printf("Digite o codigo do produto: ");
                fflush(stdin);
			    scanf("%d", &codigo);
                if (consultar(arvore, codigo) != NULL)
                	printf("Encontrou\n");
                else
                	printf("Nao encontrou!\n");
				break; 
			case 6: 
				printf("\n\n*** Excluir ***\n\n");
                printf("Digite o codigo do produto: ");
                fflush(stdin);
			    scanf("%d", &codigo);
                if (excluir(&arvore, codigo))
                	printf("Excluido\n");
                else
                	printf("Nao encontrou!\n");
		} 
	} while (op != 0);
	destruir(arvore);
	return 0; 
} 

int menu(void) { 
	int op; 
	printf("\n\n*** MENU ***\n\n"); 
	printf("1. Incluir\n"); 
	printf("2. Listar em-ordem\n"); 
	printf("3. Listar pre-ordem\n");
	printf("4. Listar pos-ordem\n");
	printf("5. Consultar\n"); 
	printf("6. Excluir\n"); 
	printf("0. Sair\n\n"); 
	printf("Digite sua opcao: "); 
	scanf("%d", &op); 
	return op; 
} 

void inicializar(struct tNo **raiz) {
	(*raiz) = NULL;
}

void incluir(struct tNo **raiz, struct tNo *novo) {
	if ((*raiz) == NULL) {
		(*raiz) = novo;
		novo->esq = novo->dir = NULL;
	}
	else {
		if (novo->dado.codigo < (*raiz)->dado.codigo)
			incluir(&((*raiz)->esq), novo);
		else
			incluir(&((*raiz)->dir), novo);
	}
}

void emordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);
	emordem(raiz->dir);
}

void preordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);	
	emordem(raiz->esq);
	emordem(raiz->dir);
}

void posordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	emordem(raiz->dir);
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);
}

struct tNo *consultar(struct tNo *raiz, int codigo) {
	if ((raiz == NULL) || (raiz->dado.codigo == codigo))
		return raiz;
	if (codigo < raiz->esq)
		return consultar(raiz->esq, codigo);
	return consultar(raiz->dir, codigo);
}

void destruir(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}

int grau(struct tNo *raiz) {
	if ((raiz->esq == NULL) && (raiz->dir == NULL))
		return 0;
	if ((raiz->esq != NULL) && (raiz->dir != NULL))
		return 2;
	return 1;
}

struct tNo *menor(struct tNo *raiz) {
	if ((raiz == NULL) || (raiz->esq == NULL))
		return raiz;
	menor(raiz->esq);
}

int excluir(struct tNo **raiz, int codigo) {
	struct tNo *p;
	if (*raiz == NULL)
		return 0;
	if ((*raiz)->dado.codigo == codigo) {
		if (grau(*raiz) == 0) { // folha
			free(*raiz);
			*raiz = NULL;
		}
		else {
			if (grau(*raiz) == 1) {
				p = *raiz;
				if ((*raiz)->esq != NULL)
					*raiz = (*raiz)->esq;
				else
					*raiz = (*raiz)->dir;
				free(p);
			}
			else { // 2 filhos
				p = menor((*raiz)->dir);
				(*raiz)->dado.codigo = p->dado.codigo;
				excluir(&((*raiz)->dir), p->dado.codigo);
			}
		}
		return 1;
	}
	if (codigo < (*raiz)->esq)
		return excluir(&((*raiz)->esq), codigo);
	return excluir(&((*raiz)->dir), codigo);
}
