#include <stdio.h>
#include <stdlib.h>

void liberar(int **vet2){
    free(*vet2);
    *vet2 = NULL;
}

int main(){
    int vet[5] = {4,2,3,4,10};
    int *vet2 = (int*)malloc(sizeof(int)*5);
    if(vet2 == NULL){
        printf("Erro!");
        return 1;
    }
    for(int i = 4; i >= 0; i--){
        *(vet2 + i) = *(vet + (4 - i));
    }
    for(int j = 0; j < 5; j++)
        printf("\n%d", vet2[j]);  
    liberar(&vet2);
    return 0;
}
