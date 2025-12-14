#include <stdio.h>

printf("=-=-=-=-=");
printf("CONTADOR DE BINARIOS");
printf("=-=-=-=-=");

void conta_binario(int matrix[3][3], int tam);
int main(){
    int matrix[3][3];
    int tam = 3;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("Informe valor para a posicao %d %d:", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
     for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    conta_binario(matrix,tam);
    return 0;
}

void conta_binario(int matrix[3][3], int tam){
    int soma0 = 0;
    int soma1 = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(matrix[i][j] == 0){
                printf("\nPosicao [%d, %d] possui valor 0", i, j);
                soma0 += 1;
            }else if(matrix[i][j] == 1){
                printf("\nPosicao [%d, %d] possui valor 1", i, j);
                soma1 += 1;
            }
        }
    }
    printf("\nA matriz possui %d zeros e %d uns", soma0, soma1);
}
