#include <stdio.h>
#include <stdlib.h>

int *alocar(int tam){
    int *vet = (int*)malloc(sizeof(int)*tam);
    if(!vet) return NULL;
    return vet;
}

void percorrer(int *vet, int tam){
     if(vet == NULL) return;
     for(int i = 0; i < tam; i++){
        printf("Informe valor para pos %d:",i);
        scanf("%d",&(vet[i]));
     }
     printf("Vet: ");
     printf("(");
     for(int j = 0; j < tam; j++){
        printf("%d",*(vet+j));
        j < (tam - 1) ? printf(",") : printf("");
     }
     printf(")");
}

void liberar_memoria(int **pp){
   free(*pp);
   *pp = NULL;
}

int main(){
   int *vet = NULL;
   int tam;
   printf("Informe tamanho do vetor:");
   scanf("%d",&tam);
   if(tam <= 0){
     printf("Informe tamanho do vetor:");
     scanf("%d",&tam);
   }
   vet = alocar(tam);
   percorrer(vet,tam);
   liberar_memoria(&vet);
}