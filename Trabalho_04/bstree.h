#ifndef _BSTREE_H_
#define _BSTREE_H_

	#ifdef _BSTREE_C_
		typedef struct _treeNode_ {
		    struct _treeNode_ *l, *r;
		    void *data;
		} TNode;

		TNode* abpCreate();
		void PreOrdem(TNode *tNode, void (*visit)(void *item));
		void Simetrica(TNode *tNode, void (*visit)(void *item));
		void PosOrdem(TNode *tNode, void (*visit)(void *item));
		TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*));
		TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*));
		void* abpQuery(TNode *t, void *key, int(*cmp)(void*, void*));
		int abpAltura(TNode* t);
		int abpCountNodes(TNode *t);
		int abpIsEmpty(TNode *t);


	#else	

		typedef struct _treeNode_ TNode;
		
		TNode* abpCreate();
		void PreOrdem(TNode *tNode, void (*visit)(void *item));
		void Simetrica(TNode *tNode, void (*visit)(void *item));
		void PosOrdem(TNode *tNode, void (*visit)(void *item));
		TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*));
		TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*));
		void* abpQuery(TNode *t, void *key, int(*cmp)(void*, void*));
		int abpCountNodes(TNode *t);
		int abpIsEmpty(TNode *t);
		int abpAltura(TNode* t);

	#endif 

#endif