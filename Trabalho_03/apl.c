#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "myLib.c"


int main(){
	int TotalElms, opcao = 0;
	SLList *pessoas = NULL;
	

	do{
		printMenu();
		setbuf(stdin, NULL);
		scanf("%d", &opcao);
		if(opcao == 0){
			if (pessoas == NULL){
				return 0;
			}else{
				printf("ERRO: lista alocada na memoria \nPara prosseguir destrua a lista\n");
				opcao = -1;
			}
		}else if(opcao == 1){
			if(pessoas != NULL){
				printf("Lista ja criada\n");
			}else{
				printf("Digite capacidade total da colecao:");
				setbuf(stdin, NULL);
				scanf("%d", &TotalElms);
				pessoas = colCreate(TotalElms);
			}
	
		}else if(opcao == 2){
			if(pessoas != NULL){
				criaPessoa(pessoas);
			}else{
				printf("ERRO: Colecao inexistente\n");
			}

		}else if(opcao == 3){
			//codigo para procurar elementos na coleção
			
			if(pessoas != NULL){
				ProcuraPessoa(pessoas);
			}else{
				printf("ERRO: Colecao inexistente\n");
			}

		}else if(opcao == 4){
			//codigo para remover elementos
			
			if(pessoas != NULL){
				removePessoa(pessoas);
			}else{
				printf("ERRO: Colecao inexistente\n");
			}

		}else if(opcao == 5){
			//codigo para listar todos os elemetos da coleção

			if(pessoas != NULL){
				printTodasPessoas(pessoas);
			}else{
				printf("ERRO: Colecao inexistente\n");
			}

		}else if(opcao == 6){
			//codigo para destruir coleção;
			
			if(pessoas != NULL){
				destruirColecao(pessoas);
				pessoas = NULL;
			}else{
				printf("ERRO: Colecao inexistente\n");
			}
		}else{
			printf("Opcao invalida \nDigite uma opcao valida\n");
		}



	}while(opcao != 0);
	return 0;
}

