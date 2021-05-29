#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
FILE * readFile(){
  setlocale(LC_ALL,""); //Acentuação
  clock_t start = clock(); //Tempo de execução
  FILE *fp;

  fp = fopen("data/obito_cartorio.csv", "r");
  if (!fp) {
    printf("\n\nNão foi possível abrir o arquivo\n");
    exit(0);
  }

  printf("Arquivo aberto com sucesso!\n\n");

  //Mostrar tempo de execução
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo de execução %.5fms\n\n", elapsed);

  return(fp);

}