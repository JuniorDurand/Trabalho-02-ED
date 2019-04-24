#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <lib.h>


//PREENCHE A MATRIZ COM OS VALORES DO ARQUIVO
float* LerMatrizArquivo(FILE* arq){
  int n, m;
  if(arq != NULL){
    fseek( arq, 0, SEEK_SET);
    float* matrizA = (float*)malloc(sizeof(float)*n*m);
    fscanf( arq,"%d %d", &n, &m);

    if(matrizA != NULL){  // TESTE DE ALOCACAO
      if(n>0 && m>0){     // TESTE SE AS LINHAS E COLUNAS POSSUEM VALOR VALIDO
        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            fscanf(arq,"%f", &matrizA[i*m+j]);
            //printf("%.2f ", matrizA[i*m+j]);
          }
          //printf("\n");
        }
        return matrizA;
      }
    }
  }
  return NULL;
}


//RETORNA UMA MATRIZ TRANSPOSTA EM UM VETOR, DA MATRIZ-A
float* returnTransposta(int n, int m, float* matrizA){
  if(matrizA != NULL){
    float* matrizTransp = (float*)malloc(sizeof(float)*m*n);
    if(matrizTransp != NULL){
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          matrizTransp[j*n+i] = matrizA[i*m+j];
        }
      }
      return matrizTransp;
    }    
  }
  return NULL;
}


//IMPRIME A MATRIZ TRANSPOSTA DE MATRIZ-A
void printaTransposta(int n, int m, float* matrizA){
  if(matrizA != NULL){
    if(matrizA != NULL){
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          printf("[%.2f]",matrizA[j*m+i]);
        }
        printf("\n");
      }
    }    
  }
}


// PRINTA O RESULTADO DE MATRIZ-A * TRANSPOSTA-DA-MATRIZ-B
void multMatrizAMatrizBTransp(int n, int m, int p, int q, float* matrizA, float* matrizB){
  if(m==q){
    matrizB = returnTransposta(p, q, matrizB);
    if(matrizA != NULL && matrizB != NULL){
      float* matrizResultante = (float*)malloc(sizeof(float)*n*p);
      if(matrizResultante != NULL){
        printMultiplDeMatrizes(n, m, q, p, matrizA, matrizB);
      }
    }else{
      printf("ERRO: Matrizes nulas\n");
    }
  }else{
    printf("ERRO: Matrizes Invalidas Para a operação\n");
  }
}


//IMPRIME NA TELA A MATRIZ RESULTANTE DO PRODUTO DE MATRIZ-A E MATRIZ-B
void printMultiplDeMatrizes(int n, int m, int p, int q, float* matrizA, float* matrizB){
  if(m==p){
    if(matrizA != NULL && matrizB != NULL){
      for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
          float somatoria = 0.0;
          for(int k=0; k<m; k++){
            somatoria += matrizA[i*m+k] * matrizB[k*q+j];
          }
            printf("[%.2f]",somatoria);
        }
        printf("\n");
      }
    }
  }else{
  printf("ERRO: Matrizes Invalidas Para a operação\n");
  }
}


//IMPRIME OS ELEMENTOS DA TRIANGULAR SUPERIOR DA MATRIZ-A
void triangularSuperior(int n, int m, float* matrizA){
  if(matrizA != NULL){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(j>i){
          printf("[%.2f]", matrizA[i*m+j]);
        }
      }
    }
  }else{
    printf("ERRO: MATRIZ NULA\n");
  }
}


//IMPRIME OS ELEMENTOS DA DIAGONAL PRINCIPAL DA MATRIZ-A
void diagonalPrincipal(int n, int m, float* matrizA){
  int menor;
  if(matrizA != NULL){
    if(n<m){
      menor = n;
    }else{
      menor = m;
    }
    for(int i=0; i<menor; i++){
      printf("[%.2f]",matrizA[i*m+i]);
    }
  }else{
    printf("ERRO: MATRIZ NULA\n");
  }
}


//IMPRIME A LINHA K (1º POSICAO i=0) DA MATRIZ-A
void printLinhaK(int n, int m, float* matrizA){
  int k, flag;
  if(matrizA != NULL){
    do{
      printf("Digite a linha a ser impressa:");
      scanf("%d",&k);
      if(k>=0 && k < n){
        flag = false;
        for(int i=0; i<m; i++){
          printf("[%.2f]",matrizA[k*m+i]);
        }
      }else{
        flag = true;
        printf("Linha invalida ou inexistente\n");
      }
    }while(flag);
  }else{
    printf("ERRO: MATRIZ NULA\n");
  }
}


//IMPRIME A COLUNA K (1º POSICAO i=0) DA MATRIZ-A
void printColunaK(int n, int m, float* matrizA){
  int k, flag;
  if(matrizA != NULL){
    do{
      printf("Digite a coluna a ser impressa:");
      scanf("%d",&k);
      if(k>=0 && k<m){
        flag = false;
        for(int i=0; i<n; i++){
          printf("[%.2f]",matrizA[i*m+k]);
        }
      }else{
        flag = true;
        printf("Coluna invalida ou inexistente\n");
      }
    }while(flag);
  }else{
    printf("ERRO: MATRIZ NULA\n");
  }
}


//IMPRIME O MENU DE OPCOES
void printMenu(){
  printf("\n");
  printf("1 - IMPRIME MATRIZ-A * MATRIZ-B\n");
  printf("2 - IMPRIME MATRIZ-A * TRANSPOSTA DE MATRIZ-B\n");
  printf("3 - IMPRIME TRANSPOSTA DE MATRIZ-A\n");
  printf("4 - IMPRIME TRIANGULAR SUPERIOR DE MATRIZ-A\n");
  printf("5 - IMPRIME DIAGONAL PRINCIPAL DE MATRIZ-A\n");
  printf("6 - IMPRIME LINHA 'K' DA MATRIZ-A \n");
  printf("7 - IMPRIME COLUNA 'K' DA MATRIZ-A \n");
  printf("8 - IMPRIME MATRIZ-A \n");
  printf("9 - IMPRIME MATRIZ-B \n");
  printf("10 - SAIR\n");
  printf("\n");
  printf("DIGITE UMA OPCAO: ");
}


//IMPRIME A MATRIZ MATRIZ-A
void printMatriz(int n, int m, float* matrizA){
  if(matrizA != NULL){
    printf("\n------------\n");
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        printf("[%.2f]", matrizA[i*m+j]);
      }
      printf("\n");
    }
    printf("\n------------\n");
  }else{
    printf("ERRO: MATRIZ NULA\n");
  }
}