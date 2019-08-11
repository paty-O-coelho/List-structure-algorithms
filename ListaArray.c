#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define TAM_MAX 10

struct lista {
	int ini, fim;
	int itens[TAM_MAX];
};

Lista * criar() {
	Lista * l = malloc(sizeof(Lista));	
	l->ini = l->fim = 0;
	return l;
}

void destruir(Lista * l) {
	if (l != NULL) {
		free(l);
	}
}

void limpar(Lista * l) {
	l->ini = l->fim = 0;		
}

int tamanho(Lista * l) {
	return l->fim - l->ini;	
}

int esta_vazia(Lista * l) {
	return tamanho(l) == 0;	
}

int ler_pos(Lista * l, int p) {
	if (p < 0 || p >= tamanho(l)) {
		printf("Posição inválida!\n");
		return -1;
	}
	return l->itens[l->ini + p];
}

int primeiro(Lista * l) {
	return ler_pos(l, 0);
	//return l->itens[l->ini];
}

int ultimo(Lista * l) {
	return ler_pos(l, tamanho(l)-1);
	//return l->itens[l->fim-1];
}

int buscar(Lista * l, int v) {
	int i;
	for (i=l->ini; i<l->fim; i++) {
		if (l->itens[i] == v) {
			return i-l->ini;
		}
	}
	return -1;
	/* 
	int i;
	for (i=0; i<tamanho(l); i++) {
		if (ler_pos(i) == v) {
			return i;
		}
	}
	return -1;
	*/	
}

void imprimir(Lista * l) {
	int i;
	printf("[ ");
	for (i=l->ini; i != l->fim; i++) {
		printf("%d ", l->itens[i]);
	}
	printf("]\n");
}

void escrever_pos(Lista * l, int p, int v) {
	if (p < 0 || p >= tamanho(l)) {
		printf("Posição inválida!\n");
		return -1;
	}
	l->itens[l->ini + p] = v;	
}

void inserir_pos(Lista * l, int p, int v) {
	int i, tam = tamanho(l);
	if (p < 0 || p > tam) {
		printf("Posição inválida!\n");
		return;
	}	
	if (tam == TAM_MAX) {
		printf("Lista cheia!\n");
		return;
	}
	//TESTA SE ESTÁ COLADO NO FIM DO ARRAY	
	if (l->fim == TAM_MAX) {
		for(i=0; i<tam; i++) {
			l->itens[i] = l->itens[l->ini+i];
		}
		l->ini = 0;
		l->fim = tam;
	}
	for (i=l->fim; i > p + l->ini; i--) {
		l->itens[i] = l->itens[i-1];
	}
	l->itens[i] = v;
	l->fim++;
}

void inserir_primeiro(Lista * l, int v) {
	inserir_pos(l, 0, v);
}

void inserir_ultimo(Lista * l, int v) {
	inserir_pos(l, tamanho(l), v);
}

int remover_pos(Lista * l, int p) {
	int i, v, tam = tamanho(l);
	if (p < 0 || p >= tam) {
		printf("Posição inválida!\n");
		return -1;
	}		
	for (i=p+l->ini, v=l->itens[i]; i < l->fim-1; i++) {
		l->itens[i] = l->itens[i+1];
	}	
	l->fim--;
	return v;
}

int remover_primeiro(Lista * l) {
	return remover_pos(l, 0);
}

int remover_ultimo(Lista * l) {
	return remover_pos(l, tamanho(l)-1);	
}

void remover(Lista * l, int v) {
	int i, p;
	for (i=l->ini; i<l->fim; i++) {
		if (l->itens[i] == v) {
			break;
		}
	}
	if (l->itens[i] == v) {
		for (; i < l->fim-1; i++) {
			l->itens[i] = l->itens[i+1];
		}	
		l->fim--;
	}
}

Lista * concatenar(Lista * l1, Lista * l2) {
	Lista * l3 = criar();
	int tam1 = tamanho(l1), tam2 = tamanho(l2);
	int i, j;
	if (tam1 + tam2 > TAM_MAX) {
		printf("Nova lista excede tamanho máximo!\n");
		return NULL;
	}	
	for (i=l3->fim/*=0*/, j=l1->ini; j < l1->fim; i++,j++) {
		l3->itens[i] = l1->itens[j];
	}	
	for (j=l2->ini; j < l2->fim; i++,j++) {
		l3->itens[i] = l2->itens[j];
	}	
	l3->fim = i;
	return l3;
}

void remover_nprimeiros(Lista * l, int n) {
	int tam = l->fim - l->ini;
	l->ini += n > tam ? tam : n;
}

