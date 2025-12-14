#include <stdio.h>
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
