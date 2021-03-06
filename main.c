//vose é lindo, camarada plinio!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//________Area para definição da estrutura de dados
//____Lista
typedef struct nodo {
  int length;
  char date[11]; //00-00-0000
  char state[3];//PE
  int epidemiological_week_2019, epidemiological_week_2020, deaths_indeterminate_2019, deaths_respiratory_failure_2019,deaths_others_2019, deaths_pneumonia_2019, deaths_septicemia_2019, deaths_sars_2019, deaths_covid19, deaths_indeterminate_2020, deaths_respiratory_failure_2020,deaths_others_2020, deaths_pneumonia_2020, deaths_septicemia_2020, deaths_sars_2020, deaths_total_2019, deaths_total_2020, new_deaths_indeterminate_2019, new_deaths_respiratory_failure_2019, new_deaths_others_2019, new_deaths_pneumonia_2019, new_deaths_septicemia_2019, new_deaths_sars_2019, new_deaths_covid19, new_deaths_indeterminate_2020, new_deaths_respiratory_failure_2020, new_deaths_others_2020, new_deaths_pneumonia_2020, new_deaths_septicemia_2020, new_deaths_sars_2020, new_deaths_total_2019, new_deaths_total_2020;


  struct nodo * ant; //Endereço do nó anterior
  struct nodo * prox; //Endereço do próximo nó
}NODO;
 
typedef NODO * LISTA;

//___Pilha
typedef struct nodo_pilha {
  
  int TOPO;
  char date[11]; //00-00-0000
  char state[3];//PE
  int epidemiological_week_2019, epidemiological_week_2020, deaths_indeterminate_2019, deaths_respiratory_failure_2019,deaths_others_2019, deaths_pneumonia_2019, deaths_septicemia_2019, deaths_sars_2019, deaths_covid19, deaths_indeterminate_2020, deaths_respiratory_failure_2020,deaths_others_2020, deaths_pneumonia_2020, deaths_septicemia_2020, deaths_sars_2020, deaths_total_2019, deaths_total_2020, new_deaths_indeterminate_2019, new_deaths_respiratory_failure_2019, new_deaths_others_2019, new_deaths_pneumonia_2019, new_deaths_septicemia_2019, new_deaths_sars_2019, new_deaths_covid19, new_deaths_indeterminate_2020, new_deaths_respiratory_failure_2020, new_deaths_others_2020, new_deaths_pneumonia_2020, new_deaths_septicemia_2020, new_deaths_sars_2020, new_deaths_total_2019, new_deaths_total_2020;


  // struct nodo_pilha * ant; //Endereço do nó anterior
  struct nodo_pilha * prox; //Endereço do próximo nó
}NODO_PILHA;

typedef NODO_PILHA * PILHA; 

typedef struct nodo_fila{
  int inf;
  struct nodo_fila * next;

}NODO_FILA;

typedef struct{
  NODO_FILA *INICIO_FILA;
  NODO_FILA *FIM_FILA;

}DESCRITOR;
typedef DESCRITOR * FILA;

//____Fim da Area para definição da estrutura de dados

void cria_fila(FILA *);
int fila_vazia(FILA);
void inserir_fila(FILA, char *);
int consultar_fila(FILA);
void retirar_fila(FILA);
int consultar_retirar_fila(FILA, char[], char[]);
void destruir_fila(FILA);
void mass_storage_fila (FILE *, FILA);


void cria_pilha(PILHA *);
int eh_vazia(PILHA);
void push(PILHA *, char *);
void top_pop(PILHA *, char[], char[]);
void mass_storage_pilha(FILE *, PILHA);


FILE * readFile();
void criar_lista(LISTA *);
void inserir_lista(LISTA , char *);
int  recup_lista(LISTA, char[], char[]);
int  get_pico_lista(LISTA);
void mass_storage_lista(FILE *, LISTA);
void primeira_questao(LISTA, PILHA);
void segunda_questao();

//________________________________________FILA_____________________________________________

void cria_fila(FILA *pf){
    *pf=(DESCRITOR *) malloc (sizeof(DESCRITOR));
    if(!*pf){
        printf("\nErro\n");
        exit(1);
    }
    (*pf)->INICIO_FILA=(*pf)->FIM_FILA=NULL;
}

int fila_vazia(FILA f){
    return(f->INICIO_FILA == NULL);
}

void inserir_fila(FILA f, char *string){
    NODO_FILA *novo;
    novo = (NODO_FILA*)malloc (sizeof(NODO_FILA));
    if(!novo){
        printf("\nErro\n");
        exit(2);
    }
    //novo->inf = v;
    novo->next = NULL;
    if (fila_vazia(f))
        f->INICIO_FILA=novo;
    else
        f->FIM_FILA->next=novo;
    f->FIM_FILA=novo;

}

int consultar_fila(FILA f){
    if (!f->INICIO_FILA){
        printf("\nErro\n");
        exit(3);
    }
    else
        return (f->INICIO_FILA->inf);

}

void retirar_fila(FILA f){
    if (!f->INICIO_FILA){
        printf("\nErro\n");
        exit(4);
    }else{
        NODO_FILA *aux=f->INICIO_FILA;
        f->INICIO_FILA=f->INICIO_FILA->next;
        if(!f->INICIO_FILA)
        f->FIM_FILA=NULL;
        free(aux);
    }
}


int consultar_retirar_fila(FILA f, char state[3], char date[11]){
    if (!f->INICIO_FILA){
        printf("\nErro\n");
        exit(5);
    }else{
        int v=f->INICIO_FILA->inf;
        NODO_FILA *aux=f->INICIO_FILA;
        f->INICIO_FILA=f->INICIO_FILA->next;
        if(!f->INICIO_FILA)
            f->FIM_FILA=NULL;
        free(aux);
        return(v);
    }
}
void destruir_fila(FILA f){
    NODO_FILA *aux;
    while (f->INICIO_FILA){
        aux=f->INICIO_FILA;
        f->INICIO_FILA=f->INICIO_FILA->next;
        free(aux);
    }
    free(f);
}

//___________________________________FIM DA FILA___________________________________________
//-----------------------------------------------------------------------------------------
//________________________________________PILHA____________________________________________
void cria_pilha(PILHA *p){ 
    *p = NULL;
}

int eh_vazia(PILHA p){
    return (!p);
}

void push(PILHA *pp, char *string){
  int index = 0, *pint;
  char *found, delimiter[2] = ",";
  NODO_PILHA * novo;
  novo = (NODO_PILHA *) malloc (sizeof(NODO_PILHA));

  if(!novo){
    printf("\n\nMemoria insuficiente.");
    exit(6);
  }

  pint = &novo->epidemiological_week_2019;
    while(++index, (found = strsep(&string, delimiter)) != NULL){
      if(!strcmp(found, ""))
        found = "0";
      
      if(index == 1){
       strcpy(novo->date, found);
      } else if(index == 2) {
        strcpy(novo->state, found);
      } else {
        *pint = strtol(found, NULL, 10);
        pint++;
      }
    }

    novo->prox = (*pp);
    pp = &novo;
    // printf("%s > %s\n", (novo->prox)->, (*pp)->date);
}
void top_pop (PILHA *p, char state[3], char date[11] ){

  if(!(p)){
    printf("\n\n Pilha vazia.");
    exit(7);
  }

  printf("passou aqui carai\n");

  while(!(!strcmp((*p)->state, state) && !strcmp((*p)->date, date))){

    if(!(*p)){
      printf("\nDados não encontrado na PILHA.\n");
      exit(8);
    }
    
    *p = (*p)->prox;
  }
  
}

void mass_storage_pilha(FILE *fp, PILHA pilha){
  int tamLinha = 900, c = 4, first = 1;
  char *string, linha[tamLinha];

  while(fgets(linha, tamLinha, fp)) { 

    string = strdup(linha);     
    if(first == 1){
      first = 0;
      continue;
    }
      
      push(&pilha, string);
    // printf("Done\n");  
    }
}

//____________________________________FIM DA PILHA_________________________________________
//-----------------------------------------------------------------------------------------
//____________ARVORE AVL


//____________Fim da arvore
//-----------------------------------------------------------------------------------------
//________________________________________LISTA____________________________________________
void criar_lista(LISTA *pl){
  *pl = (LISTA)malloc(sizeof(NODO));

  if(!(*pl)){
    printf("\n\nMEMÓRIA INSUFICIENTE\n\n");
    exit(100);
  }
  (*pl)->length = 0;
  (*pl)->prox = (*pl)->ant = *pl;
}
void inserir_lista(LISTA l, char *string){
  char *found, delimiter[2] = ",";
  int index = 0, *p;
  LISTA aux, novo;
  aux = l; 
  novo = (LISTA) malloc(sizeof(NODO));
  if(!novo){
    printf("\n\nMEMÓRIA INSUFICIENTE\n\n");
    exit(102);
  }  
  p = &novo->epidemiological_week_2019; // aqui eu defino a primeira variavel como index 0 do arr


   while(index++, (found = strsep(&string, delimiter)) != NULL ){
      if(!strcmp(found, ""))
        found = "0";

      if(index == 1){
        strcpy(novo->date, found);
      }else if(index == 2){
        strcpy(novo->state, found);
      }else{
        *p = strtol(found, NULL,10);
        p++;
      }
      
      l->ant->prox = novo;
      novo->ant = l->ant;
      novo->prox = l;
      l->ant = novo;
      l->length++;

   }



}
int recup_lista(LISTA l, char state[3], char date[11]){
  int tamA, tamB;
  tamA = tamB = l->length;

    while(tamA--, !(!strcmp(l->state, state) && !strcmp(l->date, date))){
      if(!tamA){
        printf("Estado e/ou Data não existem no banco\n");
        return 0;
      }
      l = l->prox;
    }

  printf("Dados encontrados\n\n");
  printf("data: %s\n", l->date);
  printf("estado: %s\n",l->state ); 
  printf("semana epidemiológica 2019: %d \n", l->epidemiological_week_2019); 
  printf("semana epidemiológica 2020: %d \n", l->epidemiological_week_2020);
  printf("óbitos indeterminados 2019: %d \n", l->deaths_indeterminate_2019);
  printf("óbitos por insuficiência respiratória 2019: %d \n", l->deaths_respiratory_failure_2019);
  printf("outros óbitos 2019: %d \n", l->deaths_others_2019);
  printf("óbitos pneumonia 2019: %d \n", l->deaths_pneumonia_2019);
  printf("óbitos septicemia 2019: %d \n", l->deaths_septicemia_2019);
  printf("óbitos sars 2019: %d \n", l->deaths_sars_2019);
  printf("óbitos covid19: %d \n", l->deaths_covid19);
  printf("óbitos indeterminados 2020: %d \n", l->deaths_indeterminate_2020);
  printf("óbitos insuficiência respiratória 2020: %d \n",l->deaths_respiratory_failure_2020);
  printf("outros óbitos 2020: %d \n", l->deaths_others_2020);
  printf("mortes por pneumonia 2020: %d \n", l->deaths_pneumonia_2020);
  printf("mortes septicemia 2020: %d \n", l->deaths_septicemia_2020);
  printf("mortes sars 2020: %d \n", l->deaths_sars_2020);
  printf("mortes totais 2019: %d \n", l->deaths_total_2019);
  printf("mortes totais 2020: %d \n", l->deaths_total_2020);
  printf("novas mortes indeterminadas 2019: %d\n", l->new_deaths_indeterminate_2019);
  printf("novas mortes por insuficiência respiratória 2019: %d\n", l->new_deaths_respiratory_failure_2019);
  printf("novas outras mortes 2019: %d\n", l->new_deaths_others_2019);
  printf("novas mortes por pneumonia 2019: %d\n", l->new_deaths_pneumonia_2019);
  printf("novas mortes septicemia 2019: %d\n", l->new_deaths_septicemia_2019);
  printf("novas mortes sars 2019: %d\n", l->new_deaths_sars_2019);
  printf("novas mortes covid19: %d\n", l->new_deaths_covid19);
  printf("novas mortes indeterminadas em 2020: %d\n", l->new_deaths_indeterminate_2019);
  printf("novas mortes por insuficiência respiratória 2020: %d\n", l->new_deaths_respiratory_failure_2020);
  printf("novas outras mortes 2020: %d\n", l->new_deaths_others_2020);
  printf("novas mortes pneumonia 2020: %d\n", l->new_deaths_pneumonia_2020);
  printf("novas mortes septicemia 2020: %d\n", l->new_deaths_septicemia_2020);
  printf("novas mortes sars 2020: %d\n", l->new_deaths_sars_2020);
  printf("novas mortes totais 2019: %d\n", l->new_deaths_total_2019);
  printf("novas mortes totais 2020: %d\n", l->new_deaths_total_2020);

  return 1;
}
int get_pico_lista(LISTA l){
  

  int length = l->length, maior = l->new_deaths_covid19;
  char date[11], state[3];

    while(length--){
      if(l->new_deaths_covid19 > maior){
        maior = l->new_deaths_covid19;
        strcpy(date, l->date);
        strcpy(state, l->state);
      }

      l = l->prox;
    }

    
    printf("Não foi encontrado nenhum dado de 2019.\n");
    printf("O pico de mortes em 2020 foi em %s em %s com %d mortos\n\n\n", state, date, maior);

    return 0;
}
void mass_storage_lista(FILE *fp, LISTA lista){
  int tamLinha = 900, c = 4, first = 1;
  char *string, linha[tamLinha];
 
 while(fgets(linha, tamLinha, fp)) { 

    string = strdup(linha);     
    if(first == 1){
      first = 0;
      continue;
    }
    
    inserir_lista(lista, string);
      
    }

}
//____________________________________FIM DA LISTA__________________________________________
//-----------------------------------------------------------------------------------------
//___________________________________PRIMEIRA QUESTAO______________________________________
void primeira_questao(LISTA lista, PILHA pilha){
  system("clr || clear");

  char state[3], date[11];
  printf("___________________________________\n");
  printf("|    BUSCAR POR DATA E ESTADO     |\n");
  printf("*¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨*\n\n\n");
  printf("Digite o estado [Ex. BA para Bahia]: \n");
  scanf(" %s", state);
  printf("\n\nAgora, digite a data requerida[Ex. YYYY-MM-DD]: \n");
  scanf(" %s", date);
  //Aqui deverão ser inseridas as funções de recuperação de dados(recup) de LISTA, FILA, PILHA e ARVORE AVL

  clock_t start = clock();
  recup_lista(lista, state, date);
  clock_t stop = clock();

  printf("\nBusca em Lista concluída:\n");
  printf("Tempo decorrido: %.5fms\n\n\n", (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC);
printf("\nteste\n");
  start = clock();
  top_pop(&pilha, state, date);
  stop = clock();

  printf("\nBusca em Pilha concluída:\n");
  printf("Tempo decorrido: %.5fms\n\n\n", (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC);
printf("\nteste\n");
}
//_______________________________FIM DA PRIMEIRA QUESTAO___________________________________
//-----------------------------------------------------------------------------------------
//___________________________________SEGUNDA QUESTAO_______________________________________
void segunda_questao(LISTA lista){
  //Aqui devem ser mostrados os picos dos anos de 2019 e 2020
  system("clr || clear");
  printf("___________________________________\n");
  printf("|    BUSCAR POR DATA E ESTADO     |\n");
  printf("*¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨*\n\n\n");

  get_pico_lista(lista);

}
//_________________________________FIM SEGUNDA QUESTAO_____________________________________
//-----------------------------------------------------------------------------------------
//_________________________________________MAIN____________________________________________
int main(void) {

  LISTA lista;
  PILHA pilha;
  FILE * fp = readFile();
  int res;

  criar_lista(&lista);
  cria_pilha(&pilha);

  printf("\nAlocando dados na memória...\n\n");

  clock_t start = clock();
  mass_storage_lista(fp, lista);
  clock_t stop = clock();

  printf("\nArmazenamento em Lista Circular Duplamente Encadeada concluída:\n");
  printf("Tempo decorrido: %.5fms\n\n\n", (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC);

  fp = readFile();

  start = clock();
  //printf("Chegou aqui ein\n");
  mass_storage_pilha(fp, pilha);
  stop = clock();

  printf("\nArmazenamento em Pilha Encadeada concluída:\n");
  printf("Tempo decorrido: %.5fms\n\n\n", (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC);

 //Aqui deverá ser organizados dados em FILA, PILHA e arvore AVL 
    /*
    1 - Efetuar uma busca pelos dados referentes a uma determinada data e um estado, apresentando os mesmos na saída padrão;

    2 - Efetuar a busca pela data e local de ocorrência do pico de óbitos por COVID19 no anode 2019 e no ano de 2020, apresentando os mesmos na saída padrão.
    */
  while(1){
      
  printf("___________________________________\n");
  printf("|         MENU PRINCIPAL          |\n");
  printf("|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n");
  printf("| [1] Buscar por Data e Estado    |\n");
  printf("| [2] Buscar localidade de pico   |\n");
  printf("| [9] Fechar Programa             |\n");
  printf("*¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨*\n");
  scanf("%d", &res);
  
  if(res == 1)
    primeira_questao(lista, pilha);
  else if(res == 2)
    segunda_questao(lista);
  else if(res == 9)
    exit(103);
  else
    printf("Numero Inválido, tente novamente\n");

  }

}
