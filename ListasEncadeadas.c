#include <stdio.h>
#include <stdlib.h>

int sair = 0;

typedef struct No{
    int chave;
    struct No *prox;
}No;

typedef struct Fila{
    No *Inicio;
    No *Fim;
}Fila;

typedef struct Pilha{
    No *topo;
}Pilha;

Fila *criar_fila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->Inicio = NULL;
    fila->Fim = NULL;
    return fila;
}

Pilha *criar_pilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void enfileirar(Fila *fila, int k){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = k;
    novo->prox = NULL;
    if(fila->Fim == NULL){
        fila->Inicio = novo;
        fila->Fim = novo;
    }else{
        fila->Fim->prox = novo;
        fila->Fim = novo;
    }
}

void empilhar(Pilha *pilha, int k){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave=k;
    novo->prox = NULL;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(Pilha *pilha){
    if(pilha->topo == NULL){
        printf("Pilha vazia!");
        return 0;
    }
    int valor = pilha->topo->chave;
    No *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return valor;
}

int desenfileirar(Fila *fila){
    if(fila -> Inicio == NULL){
        printf("Fila vazia!");
        return 0;
    }
    int valor = fila->Inicio->chave;
    No *temp = fila->Inicio;
    fila->Inicio = fila->Inicio->prox;
    if(fila->Inicio == NULL){
        fila->Fim = NULL;
    }
    free(temp);
    return valor;
}

void imprimir_pilha(Pilha *pilha){
    No *aux = pilha->topo;
    while(aux!=NULL){
        printf("%d",aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimir_fila(Fila *fila){
    No *aux = fila->Inicio;
    while(aux!=NULL){
        printf("%d",aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

void Init(){
    Pilha *pilha = criar_pilha();
    Fila *fila = criar_fila();
    int op = 0;
    int var, tam;
    char Des;
    int roll;
    while(sair == 0){
        printf("\nBem vindo ao simulador de listas dinâmicas, o que gostaria de fazer?");
        printf("\n1-Enfileirar\n2-Empilhar\n3-Sair:");
        scanf("%d",&op);
        if(op == 3) sair = 1;
        switch(op){
            case 1:
            {
                printf("Informe o tamanho da Fila:");
                scanf("%d",&tam);
                if(tam<0){
                    printf("Tamanho Invalido!");
                    Init();
                }
                for(int i = 0; i < tam; i++){
                    printf("Escolha um valor a ser enfileirado:");
                    scanf("%d",&var);
                    enfileirar(fila,var);
                }
                printf("\n=-=-=-=\n");
                imprimir_fila(fila);
                printf("=-=-=-=\n");
                printf("\nGostaria de desenfileirar? S/N:");
                scanf(" %c",&Des);
                if(Des == 'S' || Des == 's'){
                    printf("\nInforme quantas vezes para desenfileirar:");
                    scanf("%d",&roll);
                    if(roll > tam){
                        printf("\nValor fora do lmite da fila!");
                        op = 1;
                    }
                    for(int i = 0; i < roll; i++){
                        printf("\nValor desenfileirado: %d",desenfileirar(fila));
                    }
                    if(fila->Inicio == NULL){
                        printf("\nFila vazia!");
                    }else{
                        printf("\n=-=-=-=\n");
                        imprimir_fila(fila);
                        printf("=-=-=-=\n");
                    }
                }
            }break;

            case 2:
            {
                printf("Informe o tamanho da Pilha:");
                scanf("%d",&tam);
                if(tam<0){
                    printf("Tamanho Invalido!");
                    Init();
                }
                for(int i = 0; i < tam; i++){
                    printf("Escolha um valor a ser empilhado:");
                    scanf("%d",&var);
                    empilhar(pilha,var);
                }
                printf("\n=-=-=-=\n");
                imprimir_pilha(pilha);
                printf("=-=-=-=\n");
                printf("\nGostaria de desempilhar? S/N:");
                scanf(" %c",&Des);
                if(Des == 'S' || Des == 's'){
                    printf("\nInforme quantas vezes para desempilhar:");
                    scanf("%d",&roll);
                    if(roll > tam){
                        printf("\nValor fora do limite da pilha!");
                        op = 1;
                    }
                    for(int i = 0; i < roll; i++){
                        printf("\nValor desempilhado: %d",desempilhar(pilha));
                    }
                    if(pilha->topo == NULL){
                        printf("\nPilha Vazia!");
                    }else{
                        printf("\n=-=-=-=\n");
                        imprimir_pilha(pilha);
                        printf("=-=-=-=\n");
                    }
                }
            }break;
           
            case 3:
            {
                printf("\nAte mais!! :)");
            }break;
            default:
            {
                printf("Opção Invalida!");
                Init();
            }
        }
    }
}


int main(){
    do{
        Init();
    }while(sair == 0);
    return 0;
}

    

