#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "myLib.c"


int main(){
	int TotalElms, opcao = 0;
	printf("Digite capacidade total da colecao:");
	setbuf(stdin, NULL);
	scanf("%d", &TotalElms);
	Col *pessoas = colCreate(TotalElms);
	if(pessoas == NULL){
		return 0;// TESTA SE FOI ALOCADA A MATRIZ
	}

	do{
		printMenu();
		setbuf(stdin, NULL);
		scanf("%d", &opcao);

		if(opcao == 1){
			Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
			printf("Digite o nome:");
			setbuf(stdin, NULL);
			fgets(p->nome,50,stdin);
			printf("Digite a idade:");
			setbuf(stdin, NULL);
			scanf("%d", &(p->idade));
			printf("Digite a quantidade de filhos:");
			setbuf(stdin, NULL);
			scanf("%d", &(p->numFilhos));
			printf("Digite o salario:");
			setbuf(stdin, NULL);
			scanf("%f", &(p->salario));
			printf("Digite o CPF:");
			setbuf(stdin, NULL);
			fgets(p->CPF,15,stdin);
			int flag = colInsert(pessoas, (void*)p);
			if(flag){
				printf("Elemento inserido com sucesso\n");
			}else{
				printf("Elemento não inserido na colecao\n");
			}

		}else if(opcao == 2){
			//codigo para procurar elementos na coleção
			ProcuraPessoa(pessoas);
		}else if(opcao == 3){
			//codigo para remover elementos
		}else if(opcao == 4){
			//codigo para listar todos os elemetos da coleção
			printf("\n---------------\n");		
			Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
			p = (Pessoa*)colQueryFirst(pessoas);
			while(p != NULL){
				printPessoa(p);
				printf("\n---------------\n");
				p = (Pessoa*)colQueryNext(pessoas);
			}
		}else if(opcao == 5){
			//codigo para destruir coleção;
		}else{
			//codigo de opcao invalida
		}



	}while(opcao != 5);
	return 0;
}

