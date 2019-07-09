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
			//codigo para sair do programa

			if (pessoas == NULL){
				return 0;
			}else{
				printf("ERRO: estrutura alocada na memoria \nPara prosseguir destrua a estrutura\n");
				opcao = -1;
			}
		
		}else if(opcao == 1){
			//codigo para criar estrutura

			if(pessoas == NULL){
				pessoas = criaStruct();
				if(pessoas != NULL){
					printf("estrutura criada com sucesso\n");
				}else{
					printf("estrutura nao criada com sucesso\n");
					pessoas = NULL;
				}
			}else{
				printf("ERRO: Estrutura ja alocada\n");
			}

		}else if(opcao == 2){
			if(pessoas != NULL){
				criaPessoa(pessoas);
			}else{
				printf("ERRO: Estrutura inexistente\n");
			}

		}else if(opcao == 3){
			//codigo para procurar elementos na estrutura
			
			if(pessoas != NULL){
				ProcuraPessoa(pessoas);
			}else{
				printf("ERRO: Estrutura inexistente\n");
			}

		

		}else if(opcao == 4){
			//codigo para remover elementos
			
			if(pessoas != NULL){
				removePessoa(pessoas);
			}else{
				printf("ERRO: Estrutura inexistente\n");
			}
	
		

		}else if(opcao == 5){
			//codigo para exibir todos os elemetos da estrutura

			if(pessoas != NULL){
				printTodasPessoas(pessoas);
			}else{
				printf("ERRO: Estrutura inexistente\n");
			}

		

		}else if(opcao == 6){
			//codigo para destruir estrutura;
			int flag;
			if(pessoas != NULL){
				flag = destruirEstrutura(pessoas);
				if (flag){
					pessoas = NULL;
				}
			}else{
				printf("ERRO: Estrutura inexistente\n");
			}

		

		}else{
			printf("Opcao invalida \nDigite uma opcao valida\n");
		}


	}while(opcao != 0);
	return 0;
}

