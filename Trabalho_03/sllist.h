#ifndef _SLLIST_H_
#define _SLLIST_H_

	#ifdef _SLLIST_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllist_{
			SLNode* first;
			SLNode* cur;
		}SLList;
		
		SLList* sllCreate();
		int sllDestroy(sllist* list);
		int sllInsertFirst(SLList *list, void* data);
		void* sllRemoveFirst(SLList* list);
		int sllInsertLast(SLList* list, void* data);
		void* sllRemoveLast(SLList *list);
		void* sllQuery(SLList *list, void* key, int(*cmp)(void*,void*));
		void* sllRemoveSpec(SLList *list, void* key, int(*cmp)(void*,void*));
		void* sllGetFirst(SLList *list);
		void* sllGetNext(SLList* list);


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllist_ SLList;

		SLList* sllCreate();
		int sllDestroy(sllist* list);
		int sllInsertFirst(SLList *list, void* data);
		void* sllRemoveFirst(SLList* list);
		int sllInsertLast(SLList* list, void* data);
		void* sllRemoveLast(SLList *list);
		void* sllQuery(SLList *list, void* key, int(*cmp)(void*,void*));
		void* sllRemoveSpec(SLList *list, void* key, int(*cmp)(void*,void*));
		void* sllGetFirst(SLList *list);
		void* sllGetNext(SLList* list);

	#endif // _SLLIST_C_

#endif