#ifndef _COLECAO_H_
#define _COLECAO_H_

	#ifdef _COLECAO_C_
		typedef struct _colecao_{
			int max;
			int numElms;
			int cur;
			void* *elms;//vetor de void* de tamanho max
		}Col;

		Col* colCreate(int n);
		int colInsert(Col*c, void* elm);
		Col* colQuery(Col *c, int n);
		//Col* colRemove(Col *c, void* elm);
		int colDestroy(Col *c);
		void* colRemoveLast(Col *c);
		void* colRemoveFirst(Col *c);
		void* colRemoveVoid(Col *c, void *x);
		void* colRemoveN(Col *c, int n);
		void* colQueryFirst(Col *c);
		void* colQueryNext(Col *c);
		void* colQueryN(Col *c, int n);

	#else
		typedef struct _colecao_ Col;
		extern Col* colCreate(int n);
		extern int colInsert(Col*c, void* elm);
		extern Col* colQuery(Col *c, int n);
		//extern Col* colRemove(Col *c, void* elm);
		extern int colDestroy(Col *c);
		extern void* colRemoveLast(Col *c);
		extern void* colRemoveFirst(Col *c);
		extern void* colRemoveN(Col *c, int n);
		extern void* colRemoveVoid(Col *c, void *x);
		extern void* colQueryFirst(Col *c);
		extern void* colQueryNext(Col *c);
		extern void* colQueryN(Col *c, int n);


	#endif // _COLECAO_C_

#endif