#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int num;
    char cidade[50];
    char bairro[50];
    char rua[50];
    char nome[50];
} TEndereco;

void setup(TEndereco *E, int num, char cidade[], char bairro[], char rua[], char nome[]) {
    E->num = num;
    strcpy(E->cidade, cidade);
    strcpy(E->bairro, bairro);
    strcpy(E->rua, rua);
    strcpy(E->nome, nome);
}

void imprimir(TEndereco E) {
    printf("\n=-=-=-=");
    printf("\nNum = %d", E.num);
    printf("\nCidade = %s", E.cidade);
    printf("\nBairro = %s", E.bairro);
    printf("\nRua = %s", E.rua);
    printf("\nNome = %s", E.nome);
    printf("\n=-=-=-=\n");
}

int main() {
    int num, qtde;
    char cidade[50], bairro[50], rua[50], nome[50];
    printf("\nInforme quantidade de pessoas para registrar:");
    scanf("%d",&qtde);
    getchar();
    TEndereco *vet = malloc(qtde*sizeof(TEndereco));
    if(vet == NULL){
        printf("\nErro ao alocar memoria!");
        return 1;
    }

    for(int i = 0; i < qtde; i++) {
        printf("PESSOA %d",i+1);
        printf("\nInforme o numero da residencia: ");
        scanf("%d", &num);
        getchar();

        printf("Informe a cidade: ");
        fgets(cidade, 50, stdin);
        cidade[strcspn(cidade, "\n")] = '\0';

        printf("Informe o bairro: ");
        fgets(bairro, 50, stdin);
        bairro[strcspn(bairro, "\n")] = '\0';

        printf("Informe a rua: ");
        fgets(rua, 50, stdin);
        rua[strcspn(rua, "\n")] = '\0';

        printf("Informe o nome: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        setup(&vet[i], num, cidade, bairro, rua, nome);
    }

    printf("\n--- ENDERECOS CADASTRADOS ---\n");
    for(int i = 0; i < qtde; i++) {
        printf("\nENDERECO PESSOA %d",i+1);
        imprimir(vet[i]);
    }
    free(vet);
    return 0;
}
