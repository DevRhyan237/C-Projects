#include <stdio.h>

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
