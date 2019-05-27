#define _SLLIST_C_
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"
#define TRUE 1
#define FALSE 0

SLList* sllCreate(){
	SLList* list;
	list = (SLList*)malloc(sizeof(SLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
		return list;
	}
	return NULL;
}

int sllDestroy(sllist* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int sllInsertFirst(SLList *list, void* data){
	SLNode* newNode;
	if(list!=NULL){
		newNode = (SLNode*)malloc(sizeof(SLNode));
		if(newNode != NULL){
			newNode->data = data;
			newNode->next = list->first;
			list->first = newNode;
			return TRUE;
		}
	}
	return FALSE;
}

void* sllRemoveFirst(SLList* list){
	SLNode* aux;
	void* data;
	if(list != NULL){
		aux= list->first;
		list->first = aux->next;
		data = aux->data;
		free(aux);
		return data;
	}
	return NULL;
}

int sllInsertLast(SLList* list, void* data){
	SLNode* newNode;
	if(list != NULL){
		newNode = (SLNode*)malloc(sizeof(SLNode));
		if(newNode != NULL){
			newNode->data = data;
			newNode->next = NULL;
			if(list -> first == NULL){
				list -> first = newNode;
			}else{
				SLNode* cur = list->first;
				while(cur->next != NULL){
					cur= cur->next;
				}
				cur->next=newNode;
			}
			return TRUE;
		}
	}
	return FALSE;
}

void* sllRemoveLast(SLList *list){
	SLNode *last, *prev;
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			last = list-> first;
			prev = NULL;
			while(last->next != NULL){
				prev = last;
				last = last->next;
			}
			if(prev != NULL){
				prev->next=NULL;
			}else{
				list->first = NULL;
			}
			data = last->data;
			free(last);
			return data;
		}
	}
	return NULL;
}

void* sllQuery(SLList *list, void* key, int(*cmp)(void*,void*)){
	SLNode *cur;
	int stat;
	if(list != NULL){
		if(list->first != NULL){
			cur = list->first;
			stat = cmp(key, cur->data);
			while(stat != TRUE && cur->next != NULL){
				cur = cur->next;
				stat = cmp(key, cur->data);
			}
			if(stat == TRUE){
				return cur-> data;
			}
		}
	}
	return NULL;
}

void* sllRemoveSpec(SLList *list, void* key, int(*cmp)(void*,void*)){
	SLNode *spec, *prev;
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			prev = NULL;
			spec = list-> first;
			stat = cmp(key, spec->data);
			while(stat != TRUE && spec->next != NULL){
				prev = spec;
				spec = spec->next;
				stat = cmp(key, spec->data);
			}
			if(prev == NULL){
				list->first = spec->next;
			}else{
				prev->next=spec->next;
			}
			data = spec->data;
			free(spec);
			return data;
		}
	}
	return NULL;
}

void* sllGetFirst(SLList *list){
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			list->cur = list->first;
			data = list->first->data;
			return data;
		}
	}
	return NULL;
}

void* sllGetNext(SLList* list){
	void* data;
	if(list != NULL){
		if(list->cur != NULL){
			list->cur = list->cur->next;
			data = list->cur->data;
			return data;
		}
	}
	return NULL;
}