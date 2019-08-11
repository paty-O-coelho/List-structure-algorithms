#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//essa funçoes foram feitas sem usar a parte interna da lista

Lista * concatenar2(Lista * l1, Lista * l2) {
	
	Lista * l3 = criar();
	int i;
	for (i=0; i<tamanho(l1); i++) {
		inserir_ultimo(l3, ler_pos(l1, i));
	}
	for (i=0; i<tamanho(l2); i++) {
		inserir_ultimo(l3, ler_pos(l2, i));
	}
	return l3;
}

//TESTA SE L2 É SUBLISTA DE L1
int eh_sublista(Lista * l1, Lista * l2) {
	int tam1 = tamanho(l1), tam2 = tamanho(l2);
	int i, j, k;
	if (tam2 <= tam1) {
		for (i=0; i<=tam1-tam2; i++) {
			for (j=i, k=0; k<tam2; j++, k++) {
				if (ler_pos(l1, j) != ler_pos(l2, k)) {
					break;
				}
			}
			if (k == tam2) {
				return 1;
			}
		}
	}
	return 0;
}

void inverter2(Lista * l) {
	int i, j, tmp;
	for (i=0, j=tamanho(l)-1; i<j; i++,j--) {
		tmp = ler_pos(l, i);
		escrever_pos(l, i, ler_pos(l, j));
		escrever_pos(l, j, tmp);
	}
}

Lista * multiplicar_digito(Lista * l, int dig) {
	int i, v, s;
	Lista * res = criar();
	for(s=0, i=tamanho(l)-1; i>=0; i--) {
		v = ler_pos(l,i)*dig + s;
		s = v/10;
		inserir_primeiro(res, v%10);
	}
	if (s > 0) {
		inserir_primeiro(res, s);		
	}
	return res;
}

Lista * mesclar(Lista * l1, Lista * l2) {
	Lista * l3 = criar();
	int i, j, v, tam1 = tamanho(l1), tam2 = tamanho(l2);
	for(i=0; i<tam1; i++) {
		inserir_ultimo(l3, ler_pos(l1,i));
	}
	for(i=0, j=0; i<tam2; i++) {
		int tam3 = tamanho(l3);
		v = ler_pos(l2,i);
		for (; j<tam3; j++) {
			if (ler_pos(l3,j) >= v) {
				inserir_pos(l3, j, v);
				break;
			}
		}
		if (j == tam3) {
			inserir_ultimo(l3, v);
		}
	}
	return l3;	
}

int main(int argc, char *argv[]) {
	Lista * l1 = criar();
	Lista * l2 = criar();	
	Lista * l3;
	inserir_ultimo(l1, 6);	
	inserir_ultimo(l1, 8);	
	inserir_ultimo(l1, 8);		
	inserir_ultimo(l1, 5);	
	inserir_ultimo(l1, 7);	
	inserir_ultimo(l1, 9);		
	imprimir(l1);	
	remover_nprimeiros(l1, 4);
	imprimir(l1);	
	destruir(l1);
	destruir(l2);
	//destruir(l3);
	system("pause");
	return 0;
}
