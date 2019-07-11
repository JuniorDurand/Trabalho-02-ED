#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "bstree.h"

/*
*
*	Definição de estruturas
*
*/

typedef struct _pessoas_{
	TNode *pessoasCPF;
	TNode *pessoasNome;
}Pessoas;


typedef struct _pessoa_{
	char nome[50];
	int idade;
	int numFilhos;
	float salario;
	char CPF[15];
}Pessoa;


/*
*
*	Funções de comparação
*
*/


int compCPF( void *y, void *x){
	Pessoa *a = (Pessoa*)x;
	char *b = (char*)y;
	return strcmp(b, a->CPF);
}

int compStructCPF( void *y, void *x){
	Pessoa *a = (Pessoa*)x;
	Pessoa *b = (Pessoa*)y;
	return strcmp(b->CPF, a->CPF);
}


int compNome(void* y, void *x){
	Pessoa *a = (Pessoa*)x;
	char *b = (char*)y;
	return strcmp(b, a->nome);		
}

int compStructNome(void* y, void *x){
	Pessoa *a = (Pessoa*)x;
	Pessoa *b = (Pessoa*)y;
	return strcmp(b->nome, a->nome);	
}




/*
*
*	Funções de imprimir na tela
*
*/


void printMenu(){
	printf("1 - Criar Estrutura\n");
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

void printPessoa2(void *ps){
	Pessoa *p = (Pessoa*)ps; 
	if(p != NULL){
		printf("-----------------------\n");
		printf("Nome: %s",p->nome );
		printf("Idade: %d\n",p->idade);
		printf("Quantidade de filhos: %d\n",p->numFilhos);
		printf("Salario: %f\n",p->salario);
		printf("CPF: %s\n",p->CPF);
		printf("-----------------------\n");
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






void criaPessoa(Pessoas *ps){
	if(ps != NULL){
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

		ps->pessoasNome = abpInsert(ps->pessoasNome, (void*)p, compStructNome);
		ps->pessoasCPF = abpInsert(ps->pessoasCPF, (void*)p, compStructCPF);
		
	}else{
		printf("ERRO: estrutura inexistente\n");
	}

}




int procuraPorNome(Pessoas *c){
	Pessoa *p;
	char nomeProc[50];
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	p = (Pessoa*)abpQuery(c->pessoasNome, nomeProc, compNome);
	if(p != NULL){
		printPessoa(p);
		return true;
	}else{
		return false;
	}
}

int procuraPorCPF(Pessoas *c){
	Pessoa *p;
	char CPFProc[15];
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	p = (Pessoa*)abpQuery(c->pessoasCPF, CPFProc, compCPF);
	if(p != NULL){
		printPessoa(p);
		return true;
	}else{
		return false;
	}
}


void ProcuraPessoa(Pessoas *c){
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




int removePorNome(Pessoas *c){
	Pessoa *p=NULL, *pTest=NULL;
	char nomeProc[50];
	printf("Digite o nome:");
	setbuf(stdin, NULL);
	fgets(nomeProc,50,stdin);
	c->pessoasNome = abpRemove(c->pessoasNome, nomeProc, (void**)&p, compNome);
	if(p != NULL){
		c->pessoasCPF = abpRemove(c->pessoasCPF, p->CPF, (void**)&pTest, compCPF);
		if(p==pTest){
			printPessoa(p);
			free(p);
			return true;
		}
	}else{
		return false;
	}
}

int removePorCPF(Pessoas *c){
	Pessoa *p=NULL, *pTest=NULL;
	char CPFProc[15];
	int flag = true;
	printf("Digite o CPF:");
	setbuf(stdin, NULL);
	fgets(CPFProc,15,stdin);
	c->pessoasCPF = abpRemove(c->pessoasCPF, CPFProc, (void**)&p, compCPF);
	if(p != NULL){
		c->pessoasNome = abpRemove(c->pessoasNome, p->nome, (void**)&pTest, compNome);
		if(p==pTest){
			printPessoa(p);
			free(p);
			return true;
		}
	}else{
		return false;
	}
	if(flag){
	}
}

void removePessoa(Pessoas *c){
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



void printTodasPessoas(Pessoas *p){
	int stat = false;
	if(p != NULL){
		stat = abpIsEmpty(p->pessoasNome) && abpIsEmpty(p->pessoasCPF);
		if(stat != true){
			Simetrica(p ->pessoasNome, printPessoa2);
		}else{
			printf("-----------------------\n");
			printf("----Estrutura vazia----\n");
			printf("-----------------------\n");			
		}
		//Simetrica(c->pessoasCPF, printPessoa2);
	}
}


int StructDestroy(Pessoas *p){
	int flag;
	if(p != NULL){
		flag = abpIsEmpty(p->pessoasNome) && abpIsEmpty(p->pessoasCPF);
		if(flag == true){
			free(p);
			return true;
		}
	}
	return false;
}



int destruirEstrutura(Pessoas *pessoas){
	int teste = StructDestroy(pessoas);
	if(teste == true){
		pessoas = NULL;
		printf("estrutura destruida com sucesso\n");
		return true;
	}else{
		printf("Erro ao destruir a estrutura\n");
		printf("Elementos dentro da estrutura.\n");
		
	}
	return false;
}


