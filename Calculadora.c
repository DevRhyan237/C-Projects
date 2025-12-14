#include <stdio.h>

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
