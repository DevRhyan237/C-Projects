#include <stdio.h>

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
