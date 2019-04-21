#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void printPessoa(Pessoa *p){
	if(p != NULL){
		printf("Nome: %s",p->nome );
		printf("Idade: %d\n",p->idade);
		printf("Quantidade de filhos: %d\n",p->numFilhos);
		printf("Salario: %f\n",p->salario);
		printf("CPF: %s\n",p->CPF);
	}
}

void printMenuProcura(){
	printf("1 - Procurar por nome\n");
	printf("2 - Procurar por CPF\n");
}

int compCPF(void *x, char *b){
	Pessoa *a = (Pessoa*)x;
	if(strcmp(a->CPF, b)==0){
		return true;
	}else{
		return false;
	}
}






int compNome(void *x, char *b){
	Pessoa *a = (Pessoa*)x;
	if(strcmp(a->nome, b)==0){
		return true;
	}else{
		return false;
	}
}



int procuraPorNome(Col *c){
	Pessoa *p;
	char nomeProc[50];
	int flag = true;
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	p = (Pessoa*)colQueryFirst(c);
	while(p != NULL){
		if(compNome( p, nomeProc)){
			printPessoa(p);
			//flag = false;
			return true;
		}else{
			p = (Pessoa*)colQueryNext(c);
		}
	}
	if(flag){
		//printf("\nPessoa não encontrada\n");
		return false;
	}
}

int procuraPorCPF(Col *c){
	Pessoa *p;
	char CPFProc[15];
	int flag = true;
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	p = (Pessoa*)colQueryFirst(c);
	while(p != NULL){
		if(compCPF( p, CPFProc)){
			printPessoa(p);
			//flag = false;
			return true;
		}else{
			p = (Pessoa*)colQueryNext(c);
		}
	}
	if(flag){
		//printf("\nPessoa não encontrada\n");
		return false;
	}
}


Pessoa* retornaPorNome(Col *c){
	Pessoa *p;
	char nomeProc[50];
	int flag = true;
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	p = (Pessoa*)colQueryFirst(c);
	while(p != NULL){
		if(compNome( p, nomeProc)){
			flag = false;
			return p;
		}else{
			p = (Pessoa*)colQueryNext(c);
		}
	}
	if(flag){
		//printf("\nPessoa não encontrada\n");
		return NULL;
	}
}

Pessoa* retornaPorCPF(Col *c){
	Pessoa *p;
	char CPFProc[15];
	int flag = true;
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	p = (Pessoa*)colQueryFirst(c);
	while(p != NULL){
		if(compCPF( p, CPFProc)){
			flag = false;
			return p;
		}else{
			p = (Pessoa*)colQueryNext(c);
		}
	}
	if(flag){
		//printf("\nPessoa não encontrada\n");
		return NULL;
	}
}

void ProcuraPessoa(Col *c){
	if(c != NULL){
		int opcao;
		
		do{
			printMenuProcura();
			setbuf(stdin, NULL);
			scanf("%d", &opcao);
			if(opcao == 1){
				int teste;
				teste = procuraPorNome(c);
				if(!teste){
					printf("\nPessoa nao encontrada\n");
				}				

			}else if(opcao == 2){
				int teste;
				teste = procuraPorCPF(c);
				if(!teste){
					printf("\nPessoa nao encontrada\n");
				}
			}
		}while(opcao < 1 || opcao > 2);
	}
}


void removePessoa(Col *c){
	if(c != NULL){
		int opcao;
		
		do{
			printMenuProcura();
			setbuf(stdin, NULL);
			scanf("%d", &opcao);
			if(opcao == 1){
				Pessoa *pesRemov;
				pesRemov = retornaPorNome(c);
				if(pesRemov!=NULL){
					Pessoa *aux = (Pessoa*)colRemoveVoid(c, (void*)pesRemov);
					printPessoa(pesRemov);
					free(pesRemov);
					printf("Pessoa removida com sucesso\n");
				}else{
					printf("Pessoa nao encontrada\n");
				}				

			}else if(opcao == 2){
				Pessoa *pesRemov;
				pesRemov = retornaPorCPF(c);
				if(pesRemov!=NULL){
					Pessoa *aux = (Pessoa*)colRemoveVoid(c, (void*)pesRemov);
					printPessoa(pesRemov);
					free(pesRemov);
					printf("Pessoa removida com sucesso\n");
				}else{
					printf("Pessoa nao encontrada\n");
				}
			}
		}while(opcao < 1 || opcao > 2);
	}
}

int destruirColecaoESair(Col *pessoas){
	int teste = colDestroy(pessoas);
	if(teste == true){
		printf("Colecao destruida com sucesso\n");
		return 5;
	}else{
		printf("Erro ao destruir colecao\n");
		printf("Elementos dentro da colecao.\n");
		printf("Remover todos os elementos e destruir(1 - Sim/ 2 -Nao).\n");
		int remov;
		setbuf(stdin,NULL);
		scanf("%d",&remov);
		if(remov == 1){
			Pessoa *p = (Pessoa*)colRemoveLast(pessoas);
			while(p!=NULL){
				printPessoa(p);
				p = (Pessoa*)colRemoveLast(pessoas);
			}
			teste = colDestroy(pessoas);
			if (teste == true){
				printf("Colecao destruida com sucesso\n");
				return 5;
			}else{
				printf("ERRO ao destruir colecao\n");
				return 0;
			}
		}

	}
	return 0;
}