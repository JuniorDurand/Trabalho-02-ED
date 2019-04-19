//#ifndef _COLECAO_C_
#define _COLECAO_C_
#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#define TRUE 1
#define FALSE 0

/*
typedef struct _colecao_{
	int max;
	int numElms;
	int cur;
	void* *elms;//vetor de void* de tamanho max
}Col;
*/

Col* colCreate(int n){
	Col* c;
	if(n>0){
		c = (Col*)malloc(sizeof(Col));
		if(c!=NULL){
			c->elms = (void**)malloc(sizeof(void*)*n);
			if (c->elms !=NULL){
				c->max = n;
				c->numElms = 0;
				c->cur = -1;
				return c;
			}else{
				free(c);
			}
		}
	}
	return NULL;
}

int colInsert(Col *c, void *elm){
	if(c != NULL){
		if(c-> numElms < c-> max){
			c->elms[c->numElms] = elm;
			c->numElms++;
			return TRUE;
		}
	}
	return FALSE;
}

int colDestroy(Col *c){
	if(c != NULL){
		if(c->numElms == 0){
			free(c->elms);
			free(c);
			return TRUE;
		}
	}
	return FALSE;
}

void* colRemoveLast(Col *c){
	if(c != NULL){
		if(c->numElms > 0){
			void* elm;
			elm = c->elms[c->numElms-1];
			c->numElms--;
			return elm;
		}
	}
	return NULL;
}

void* colRemoveFirst(Col *c){
	if(c != NULL){
		if(c-> numElms > 0){
			Col *aux;
			aux = c->elms[0];
			for(int i=0; i<c->numElms-1; i++){
				c->elms[i]=c->elms[i+1];
			}
			c->numElms--;
			return aux;
		}
	}
	return NULL;
}

void* colRemoveN(Col *c, int n){
	if(c != NULL){
		if(c-> numElms > 0 && c->numElms > n){
			Col *aux;
			aux = c->elms[n];
			for(int i=n; i<c->numElms-1; i++){
				c->elms[i]=c->elms[i+1];
			}
			c->numElms--;
			return aux;
		}
	}
	return NULL;
}

void* colQueryFirst(Col *c){
	if(c != NULL){
		if(c-> numElms > 0){
			Col *aux;
			c->cur = 0;
			aux = c->elms[c->cur];
			c->cur++;
			return aux;
		}
	}
	return NULL;
}

void* colQueryNext(Col *c){
	if(c != NULL){
		if(c-> numElms > 0){
			if(c->cur < c->numElms){
				Col *aux;
				aux = c->elms[c->cur];
				c->cur++;
				return aux;
			}
		}
	}
	return NULL;
}

void* colQueryN(Col *c, int n){//neste metodo não usamos c->cur;
	if(c != NULL){
		if(c-> numElms > 0){
			if(n < c->numElms){
				Col *aux;
				aux = c->elms[n];
				return aux;
			}
		}
	}
	return NULL;
}

