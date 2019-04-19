#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colecao.h"


typedef struct _pessoa_{
	char nome[50];
	int idade;
	int numFilhos;
	float salario;
	char CPF[15];
}Pessoa;


void printMenu(){
	printf("1 - Inserir elemento\n");
	printf("2 - Consultar elemento\n");
	printf("3 - Remover elemento\n");
	printf("4 - Listar todos os elementos\n");
	printf("5 - Destruir estrutura e sair\n");
	printf("Digite uma opcao: \n");
}


void printPessoa(Pessoa p){
	if(p != NULL){
		printf("Nome: %s\n",p->nome );
		printf("Idade: %d\n",p->idade);
		printf("Quantidade de filhos: %d\n",p->numFilhos);
		printf("Salario: %f\n",p->salario);
		printf("CPF: %s\n",p->CPF);
	}
}

int compCPF(void *x, char *b){
	Pessoa *a = (Pessoa*)x;
	if(strcmp(a->CPF, *b)==0){
		return true;
	}else{
		return false;
	}
}



int compNome(void *x, char *b){
	Pessoa *a = (Pessoa*)x;
	if(strcmp(a->nome, *b)==0){
		return true;
	}else{
		return false;
	}
}

