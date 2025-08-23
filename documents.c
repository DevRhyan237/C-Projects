#include <stdio.h>
#include <stdlib.h>
#include <time.h>

printf("=-=-=-=-=");
printf("BANCO ONLINE");
printf("=-=-=-=-=");

float banco[5] = {0,0,0,0,0};
int tam = 5;

int menu();
void deposito(float banco[], int tam);
void saque(float banco[], int tam);
void verificar_saldo(float banco[], int tam);

int main(){
   int op;
   do{
      op = menu();
      switch(op){
         case 1:
            saque(banco, tam);
            break;
         case 2:
            deposito(banco, tam);
            break;
         case 3:
            verificar_saldo(banco, tam);
            break;
        case 4:
           printf("\nPrograma Encerrado!\n");
           break;
        default:
           printf("\nOpção Inválida!\n");
           break;
      }
   } while(op != 4);
   
   return 0;
}

int menu(){
   int op;
   printf("--- Seja bem vindo ao Banco Digital ---\n");
   printf("1 - Saque\n");
   printf("2 - Depositar\n");
   printf("3 - Verificar Saldo\n");
   printf("4 - Sair\n");
   printf("Informe sua opção: ");
   scanf("%d", &op);
   return op;
}

void deposito(float banco[], int tam){
   int conta;
   float valor;

   printf("\n--- Depósito ---\n");
   printf("Informe o número da conta (1 a %d): ", tam);
   scanf("%d", &conta);

   if (conta < 1 || conta > tam) {
       printf("Conta inválida. Por favor, tente novamente.\n");
       return;
   }

   printf("Informe o valor para depósito: ");
   scanf("%f", &valor);

   if (valor <= 0) {
       printf("O valor do depósito deve ser maior que zero.\n");
       return;
   }

   banco[conta - 1] += valor;

   printf("\nDepósito de R$ %.2f realizado com sucesso na conta %d!\n", valor, conta);
   printf("Novo saldo da conta %d: R$ %.2f\n", conta, banco[conta-1]);
}

void saque(float banco[], int tam){
   int conta;
   float valor;

   printf("\n--- Saque ---\n");
   printf("Informe o número da conta (1 a %d): ", tam);
   scanf("%d", &conta);

   if (conta < 1 || conta > tam) {
       printf("Conta inválida. Por favor, tente novamente.\n");
       return;
   }

   printf("Informe o valor a ser sacado: ");
   scanf("%f", &valor);

   if (valor <= 0) {
       printf("O valor do saque deve ser maior que zero.\n");
   } else if (banco[conta - 1] >= valor) {
      banco[conta - 1] -= valor;
      printf("\nSaque de R$ %.2f realizado com sucesso da conta %d!\n", valor, conta);
      printf("Novo saldo da conta %d: R$ %.2f\n", conta, banco[conta-1]);
   } else {
      printf("\nSaldo insuficiente. Saldo atual: R$ %.2f\n", banco[conta - 1]);
   }
}

void verificar_saldo(float banco[], int tam){
   float soma = 0;
   
   printf("\n--- Saldos das Contas ---\n");
   for(int i = 0; i < tam; i++){
       printf("Conta %d: R$ %.2f\n", i + 1, banco[i]);
       soma += banco[i];
   }
   
   printf("\nSaldo total do banco: R$ %.2f\n", soma);
}

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

printf("=-=-=-=-=");
printf("PEDRA,PAPEL E TESOURA");
printf("=-=-=-=-=");

int main() {
    srand(time(NULL));
    int computador = (rand() % 3) + 1;
    int jogador;
    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);
    printf("=-=-=-=\n");
    printf("1-Pedra, 2-Papel, 3-Tesoura\n");
    printf("\n=-=-=-=\n");
    scanf("%d", &jogador);

    printf("Jogador escolheu %d, computador escolheu %d\n", jogador, computador);

    if (jogador == computador) {
        printf("Empate!\n");
    } else {
        switch (jogador) {
            case 1: // Pedra
                if (computador == 2) {
                    printf("Papel cobre Pedra! Computador venceu!\n");
                } else {
                    printf("Pedra quebra Tesoura! Jogador venceu!\n");
                }
                break;
            case 2: // Papel
                if (computador == 1) {
                    printf("Papel cobre Pedra! Jogador venceu!\n");
                } else {
                    printf("Tesoura corta Papel! Computador venceu!\n");
                }
                break;
            case 3: // Tesoura
                if (computador == 1) {
                    printf("Pedra quebra Tesoura! Computador venceu!\n");
                } else {
                    printf("Tesoura corta Papel! Jogador venceu!\n");
                }
                break;
            default:
                printf("Inválido!\n");
                break;
        }
    }

    return 0;
}

printf("=-=-=-=-=");
printf("XADREZ");
printf("=-=-=-=-=");

int main() {
    char matriz[8][8];
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            matriz[i][j] = '.';
        }
    }
    
    for (j = 0; j < 8; j++) {
        matriz[1][j] = 'P';
    }
    matriz[0][0] = 'T';
    matriz[0][1] = 'C';
    matriz[0][2] = 'B';
    matriz[0][3] = 'Q';
    matriz[0][4] = 'K';
    matriz[0][5] = 'B';
    matriz[0][6] = 'C';
    matriz[0][7] = 'T';
    
    for (j = 0; j < 8; j++) {
        matriz[6][j] = 'p';
    }
    matriz[7][0] = 't';
    matriz[7][1] = 'c';
    matriz[7][2] = 'b';
    matriz[7][3] = 'q';
    matriz[7][4] = 'k';
    matriz[7][5] = 'b';
    matriz[7][6] = 'c';
    matriz[7][7] = 't';

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

printf("=-=-=-=-=-=");
printf("SALARIOS")
printf("=-=-=-=-=-=");

int main() {
    int total_funcionarios = 10;
    float salario, soma_salarios = 0;
    int filhos, soma_filhos = 0, funcionarios_com_filhos = 0, funcionarios_com_salario_baixo = 0;

    for (int i = 0; i < total_funcionarios; i++) {
        printf("Digite o salário do funcionário %d: ", i + 1);
        scanf("%f", &salario);
        printf("Digite o número de filhos do funcionário %d: ", i + 1);
        scanf("%d", &filhos);

        soma_salarios += salario;
        soma_filhos += filhos;

        if (salario <= 500 && filhos > 0) {
            funcionarios_com_filhos++;
        }

        if (salario <= 500) {
            funcionarios_com_salario_baixo++;
        }
    }

    float media_salarios = soma_salarios / total_funcionarios;
    float media_filhos = (float)soma_filhos / total_funcionarios;
    float percentual_com_filhos = funcionarios_com_salario_baixo > 0 ? ((float)funcionarios_com_filhos / funcionarios_com_salario_baixo) * 100 : 0;

    printf("Média salarial: R$ %.2f\n", media_salarios);
    printf("Média de filhos: %.2f\n", media_filhos);
    printf("Percentual de funcionários com salário até R$ 500,00 que possuem filhos: %.2f%%\n", percentual_com_filhos);

    return 0;
}

printf("=-=-=-=");
printf("CALCULADORA EM C");
printf("=-=-=-=");

float soma(float x, float y);
float subtracao(float x,float y);
float multiplicacao(float x,float y);
float divisao (float x,float y);
int menu();

int main()
{
    printf("=-=-=-=");
    printf("\nCALCULADORA EM C");
    printf("\n=-=-=-=\n");
    int x, y, res;
    printf("Informe num1:");
    scanf("%d",&x);
    printf("Informe num2:");
    scanf("%d",&y);
    int op = menu();
    if(op == 1)
        {
            printf("A soma vale %d",soma(x,y));
        }
    if(op == 2)
        {
            printf("A diferença vale %d",subtracao(x,y));
        }
    if(op == 3)
        {
            printf("O produto vale %d",multiplicacao(x,y));
        }
    if(op == 4)
       {
           printf("O quociente vale %f",divisao(x,y));
       }
    if(op == 5)
       {
           printf("Obrigado, Volte Sempre!!");
       }
} 

int menu(){
    int op;
    printf("Escolha opção:\n1-Soma\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Sair\nR:");
    scanf("%d",&op);
    while(op < 1 || op > 5)
       {
           printf("Inválido");
           menu();
       }
    return op;
}

float soma(float x, float y)
{
    return x + y;
}

float subtracao(float x,float y)
{
    return x - y;
}

float multiplicacao(float x,float y)
{
    return x*y;
}
float divisao(float x,float y)
{
    return x/y;
}
