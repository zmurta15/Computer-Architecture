/*
 * transposta - ficha 10 MIEI 17/18
 * DI-FCT/UNL
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>


// experimente com dimensoes maiores
#define DIM_MATRIZ (7*1024)

#define MAX_VAL 256

#define MIN(A,B)  (((A) < (B)) ? A : B)

int orig[DIM_MATRIZ][DIM_MATRIZ];
int destA[DIM_MATRIZ][DIM_MATRIZ];
int destB[DIM_MATRIZ][DIM_MATRIZ];


/* Inicializacao das matrizes */
void  initMatrixes (void) {
  int i, j;
  for (i=0; i<DIM_MATRIZ; i++)
    for (j=0; j<DIM_MATRIZ; j++) {
      orig[i][j] = rand() % MAX_VAL;
      destA[i][j] = destB[i][j] = 0;
    }
}

/* Transpoe um (sub)bloco de uma matriz maior */
void  transposeBlock (int src[DIM_MATRIZ][DIM_MATRIZ], int dest[DIM_MATRIZ][DIM_MATRIZ], int line, int column, int dim) {
  int i, j;
  int I = MIN(line+dim,DIM_MATRIZ), J = MIN(column+dim,DIM_MATRIZ);
  for (i=line; i<I; i++)
    for (j=column; j<J; j++) {
      dest[j][i] = src[i][j];
    }
}

/* Transpoe matriz orig para A */
void  versaoA (void) {
  transposeBlock (orig, destA, 0, 0, DIM_MATRIZ);
}


/* Transpoe matriz orig para B */
void  versaoB (int blockSize) {
  f
  printf ("ERROR: Por favor implemente a sua Versão B!\n");
}


/* Compara as matrizes A e B */
void checkVersoesAB (void) {
  int i, j;
  int areEqual = 1;
  for (i=0; i<DIM_MATRIZ && areEqual; i++)
    for (j=0; j<DIM_MATRIZ && areEqual; j++)
      if (destA[i][j] != destB[i][j])
        areEqual = 0;
  if( areEqual == 1)
    printf ("Matriz A = Matriz B\n:) :) :)\n");
  else
    printf ("ERRO!!!! Matriz A != Matriz B\n:( :( :(\n");
}


/* Calcula a diferença entre duas leituras do relogio
  Retorna resultado em segundos */
double timeElapsed (unsigned long start, unsigned long end) {
  unsigned long micros = (end - start);
  return micros / 1000000.0 ;
}


/* A funcao principal */
int main(int argc, char *argv[]) {
  
  unsigned long tAstart, tAend, tBstart, tBend;
  double timeA, timeB;
  int blockSize;
  
  // Valida argumentos
  if (argc != 2) {
    printf ("Utilizar: %s <BLOCK_SIZE>\n", argv[0]);
    exit (1);
  }
  
  
  blockSize = atoi (argv[1]);
  assert ((blockSize > 0) && (blockSize <= DIM_MATRIZ));

  printf("Init...\n");
  initMatrixes ();
  printf("Starting...\n");

  tAstart = clock ();
  versaoA ();
  tAend = clock ();
  timeA = timeElapsed (tAstart, tAend);
  printf ("Execução: versaoA = %6.3lf segundos!\n", timeA );

  tBstart = clock ();
  versaoB (blockSize);
  tBend = clock ();
  timeB = timeElapsed (tBstart, tBend);
  printf ("Execução: versaoB = %6.3lf segundos!\n", timeB );
  
  printf("speedup = %5.2f\n", (timeB>0? timeA/timeB: 0) );

  printf("Comparing...\n");
  checkVersoesAB ();
  
  // printMatrix (orig, "ORIG");
  // printMatrix (destA, "destA");
  // printMatrix (destB, "destB");
  
  return 0;  
}
