#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "myLib.c"


int main(){
	int TotalElms, opcao = 0;
	printf("Digite capacidade total da colecao:");
	scanf("%d", &TotalElms);
	Col *pessoas = colCreat(TotalElms);
	if(pessoas == NULL){
		return 0;// TESTA SE FOI ALOCADA A MATRIZ
	}

	do{
		printMenu();
		scanf("%d", &opcao);

		if(opcao == 1){
			Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
			printf("Digite o nome:");
			fflush(stdin);
			fgets(p->nome,50,stdin);
			fflush(stdin);
			printf("Digite a idade:");
			scanf("%d", &(p->idade));
			fflush(stdin);
			printf("Digite a quantidade de filhos:");
			scanf("%d", &(p->numFilhos));
			fflush(stdin);
			printf("Digite o salario:");
			scanf("%d", &(p->salario));
			fflush(stdin);
			printf("Digite o CPF:");
			fgets(p->CPF,15,stdin);
			int flag = colInsert(pessoas, (void*)p);
			if(flag){
				printf("Elemento inserido com sucesso\n");
			}else{
				printf("Elemento não inserido na colecao\n");
			}

		}else if(opcao == 2){
			//codigo para procurar elementos na coleção
		}else if(opcao == 3){
			//codigo para remover elementos
		}else if(opcao == 4){
			//codigo para listar todos os elemetos da coleção
			printf("\n---------------\n");		
			Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
			p = (Pessoa*)colQueryFirst(c);
			while(p != NULL){
				printf("Nome: %s\n",p->nome );
				printf("Idade: %d\n",p->idade);
				printf("Quantidade de filhos: %d\n",p->numFilhos);
				printf("Salario: %f\n",p->salario);
				printf("CPF: %s\n",p->CPF);
				p = (Pessoa*)colQueryNext(c);
				printf("\n---------------\n");
			}
		}else if(opcao == 5){
			//codigo para remover elementos
		}else{
			//codigo de opcao invalida
		}



	}while(opcao != 5);
	return 0;
}

