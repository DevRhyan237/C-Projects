#include <stdio.h>

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
