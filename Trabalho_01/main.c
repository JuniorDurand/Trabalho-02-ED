#include <stdio.h>
#include <lib.h>


int main(void) {
  int n, m, p, q;
  int opcao;
  float* matrizA;
  float* matrizB;

  //ABRINDO ARQUIVOS 
  FILE* arq1 = fopen("matrizA.txt", "r");
  FILE* arq2 = fopen("matrizB.txt", "r");
  
  //LENDO MATRIZES
  if(arq1 != NULL && arq2 != NULL){
    
    //LENDO MATRIZ-A
    fscanf(arq1, "%d %d", &n, &m);
    matrizA = LerMatrizArquivo(arq1);

    printf("\n");
    //LENDO MATRIZ-B
    fscanf(arq2, "%d %d", &p, &q);
    matrizB = LerMatrizArquivo(arq2);

  }else{
    printf("ERRO NA ABERTURA DE ARQUIVOS\n");
    return -1;

  }

  if(matrizA != NULL && matrizB != NULL){
    //IMPLEMENTACAO DO MENU
    do{

      printMenu();
      scanf("%d", &opcao);

      switch(opcao){
        case 1:
          printMultiplDeMatrizes( n, m, p, q, matrizA, matrizB);
          break;
        case 2: 
          multMatrizAMatrizBTransp( n, m, p, q, matrizA, matrizB);
          break;
        case 3:
          printaTransposta( n, m, matrizA);
          break;
        case 4:
          triangularSuperior( n, m, matrizA);
          break;
        case 5:
          diagonalPrincipal( n, m, matrizA);
          break;
        case 6:
          printLinhaK( n, m, matrizA);
          break;
        case 7:
          printColunaK( n, m, matrizA);
          break;
        case 8:
          printMatriz( n, m, matrizA);
          break;
        case 9:
          printMatriz( p, q, matrizB);
          break;
        case 10:
          break;

        default:
          printf("OPCAO INVALIDA\n");
      };
      printf("\n");

    }while(opcao!= 10);

  }else{
    printf("ERRO NA LEITURA DAS MATRIZES\n");
    return -1;
  }

  return 0;
}