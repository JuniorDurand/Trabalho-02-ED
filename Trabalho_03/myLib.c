#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "colecao.h"
#include "sllist.h"


typedef struct _pessoa_{
	char nome[50];
	int idade;
	int numFilhos;
	float salario;
	char CPF[15];
}Pessoa;


void printMenu(){
	printf("1 - Criar Lista\n");
	printf("2 - Inserir elemento\n");
	printf("3 - Consultar elemento\n");
	printf("4 - Remover elemento\n");
	printf("5 - Listar todos os elementos\n");
	printf("6 - Destruir estrutura\n");
	printf("0 - Sair\n");
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


void criaPessoa(SLList *c){
	if(c != NULL){
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
		int flag = sllInsertFirst(c, (void*)p);
		if(flag){
			printf("Elemento inserido com sucesso\n");
		}else{
			printf("Elemento não inserido na lista\n");
		}
	}else{
		printf("ERRO: lista inexistente\n");
	}

}




void printMenuProcura(){
	printf("1 - Procurar por nome\n");
	printf("2 - Procurar por CPF\n");
}


void printMenuRemover(){
	printf("1 - Remover por nome\n");
	printf("2 - Remover por CPF\n");
}


int compCPF( void *y, void *x){
	Pessoa *a = (Pessoa*)x;
	char* b = (char*)y;
	if(strcmp(a->CPF, b)==0){
		return true;
	}else{
		return false;
	}
}






int compNome(void* y, void *x){
	char *b = (char*)y;
	Pessoa *a = (Pessoa*)x;
	if(strcmp(a->nome, b)==0){
		return true;
	}else{
		return false;
	}
}



int procuraPorNome(SLList *c){
	Pessoa *p;
	char nomeProc[50];
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	p = (Pessoa*)sllQuery(c , nomeProc, compNome);
	if(p != NULL){
		printPessoa(p);
		return true;
	}else{
		return false;
	}
}

int procuraPorCPF(SLList *c){
	Pessoa *p;
	char CPFProc[15];
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	p = (Pessoa*)sllQuery(c , CPFProc, compCPF);
	if(p != NULL){
		printPessoa(p);
		return true;
	}else{
		return false;
	}
}


void ProcuraPessoa(SLList *c){
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

int removePorNome(SLList *c){
	Pessoa *p;
	char nomeProc[50];
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	p = (Pessoa*)sllRemoveSpec(c , nomeProc, compNome);
	if(p != NULL){
		printPessoa(p);
		free(p);
		return true;
	}else{
		return false;
	}
}

int removePorCPF(SLList *c){
	Pessoa *p;
	char CPFProc[15];
	int flag = true;
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	p = (Pessoa*)sllRemoveSpec(c ,CPFProc , compCPF);
	if(p != NULL){
		printPessoa(p);
		free(p);
		//flag = false;
		return true;
	}else{
		return false;
	}
	if(flag){
	}
}

void removePessoa(SLList *c){
	if(c != NULL){
		int opcao;
		
		do{
			printMenuRemover();
			setbuf(stdin, NULL);
			scanf("%d", &opcao);
			if(opcao == 1){
				int flag = removePorNome(c);
				if(flag){
					printf("Pessoa removida com sucesso\n");
				}else{
					printf("Pessoa nao encontrada\n");
				}				

			}else if(opcao == 2){
				int flag = removePorCPF(c);
				if(flag){
					printf("Pessoa removida com sucesso\n");
				}else{
					printf("Pessoa nao encontrada\n");
				}				
			}
		}while(opcao < 1 || opcao > 2);
	}
}



void printTodasPessoas(SLList *c){
	if(c != NULL){
		printf("\n---------------\n");		
		Pessoa *p ;
		p = (Pessoa*)sllGetFirst(c);
		while(p != NULL){
			//colStatus(c);
			printPessoa(p);
			printf("\n---------------\n");
			p = (Pessoa*)sllGetNext(c);
		}
	}
}




void destruirLista(SLList *pessoas){
	int teste = sllDestroy(pessoas);
	if(teste == true){
		pessoas = NULL;
		printf("Lista destruida com sucesso\n");
	}else{
		printf("Erro ao destruir a lista\n");
		printf("Elementos dentro da lista.\n");
		printf("Remover todos os elementos e destruir(1 - Sim/ 2 -Nao).\n");
		int remov;
		setbuf(stdin,NULL);
		scanf("%d",&remov);
		if(remov == 1){
			Pessoa *p = (Pessoa*)sllRemoveFirst(pessoas);
			while(p!=NULL){
				printPessoa(p);
				p = (Pessoa*)sllRemoveFirst(pessoas);
			}
			teste = sllDestroy(pessoas);
			if (teste == true){
				//pessoas = NULL;
				printf("Lista destruida com sucesso\n");

			}else{
				printf("ERRO ao destruir lista\n");
			}
		}

	}
}