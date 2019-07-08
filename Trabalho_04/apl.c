#include <stdio.h>
#include <stdlib.h>

#include "myLib.c"
#include "bstree.h"


Pessoas* criaStruct(){
	Pessoas *p;
	p = (Pessoas*)malloc(sizeof(Pessoas));
	if(p != NULL){
		p->pessoasNome = NULL;
		p->pessoasCPF = NULL;
		return p;
	}
	return NULL;
}


int main(){
	int TotalElms, opcao = 0;
	Pessoas* pessoas = NULL;
	

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
			if(pessoas == NULL){
				pessoas = criaStruct();
			}else{
				printf("ERRO: Estrutura ja alocada\n");
			}

		}else if(opcao == 2){
			if(pessoas != NULL){
				criaPessoa(pessoas);
			}else{
				printf("ERRO: Lista inexistente\n");
			}

		}else if(opcao == 3){
			//codigo para procurar elementos na coleção
			
			if(pessoas != NULL){
				ProcuraPessoa(pessoas);
			}else{
				printf("ERRO: Lista inexistente\n");
			}

		/*

		}else if(opcao == 4){
			//codigo para remover elementos
			
			if(pessoas != NULL){
				removePessoa(pessoas);
			}else{
				printf("ERRO: Lista inexistente\n");
			}
	
		*/

		}else if(opcao == 5){
			//codigo para listar todos os elemetos da coleção

			if(pessoas != NULL){
				printTodasPessoas(pessoas);
			}else{
				printf("ERRO: Lista inexistente\n");
			}

		/*

		}else if(opcao == 6){
			//codigo para destruir coleção;
			int flag;
			if(pessoas != NULL){
				flag = destruirLista(pessoas);
				if (flag){
					pessoas = NULL;
				}
			}else{
				printf("ERRO: Lista inexistente\n");
			}

		*/

		}else{
			printf("Opcao invalida \nDigite uma opcao valida\n");
		}




	}while(opcao != 0);
	return 0;
}

