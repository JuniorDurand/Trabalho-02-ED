#ifndef _LIB_H_INCLUDED
#define _LIB_H_INCLUDED


float* LerMatrizArquivo(FILE* arq);

float* returnTransposta(int n, int m, float* matrizA);

void printaTransposta(int n, int m, float* matrizA);

void multMatrizAMatrizBTransp(int n, int m, int p, int q, float* matrizA, float* matrizB);

void printMultiplDeMatrizes(int n, int m, int p, int q, float* matrizA, float* matrizB);

void triangularSuperior(int n, int m, float* matrizA);

void diagonalPrincipal(int n, int m, float* matrizA);

void printLinhaK(int n, int m, float* matrizA);

void printColunaK(int n, int m, float* matrizA);

void printMenu(void);

void printMatriz(int n, int m, float* matrizA);



#endif