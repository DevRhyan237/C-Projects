#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>

#define MASCARA 15
#define MEIO (MASCARA/2)

// Estrutura da imagem PGM
typedef struct {
    int largura, altura, varmax;
    int *data;
} TImagemPGM;

// Estrutura para threads
typedef struct {
    TImagemPGM *entrada;
    TImagemPGM *saida;
    int linha_inicial, linha_final;
} ThreadData;

// Mascara Laplaciana 15x15
int laplaciano[15][15] = {
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,448,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2}
};

// Função auxiliar: pula comentários e espaços, retorna próximo token
static int next_token(FILE *fp, char *buf, size_t buflen) {
    int c;
    do {
        c = fgetc(fp);
        if (c == '#') {
            while ((c = fgetc(fp)) != EOF && c != '\n');
        }
    } while (c != EOF && isspace(c));
    if (c == EOF) return 0;
    size_t i = 0;
    do {
        if (i + 1 < buflen) buf[i++] = (char)c;
        c = fgetc(fp);
    } while (c != EOF && !isspace(c));
    buf[i] = '\0';
    return 1;
}

// Lê PGM (P2 - texto) com suporte a comentários
TImagemPGM* lerPGM(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("Erro ao abrir arquivo"); return NULL; }

    char token[256];
    if (!next_token(fp, token, sizeof(token))) {
        fprintf(stderr, "Arquivo vazio ou inválido\n");
        fclose(fp); return NULL;
    }
    if (strcmp(token, "P2") != 0) {
        fprintf(stderr, "Formato inválido (esperado P2), encontrado: %s\n", token);
        fclose(fp); return NULL;
    }

    if (!next_token(fp, token, sizeof(token))) { fclose(fp); return NULL; }
    int largura = atoi(token);
    if (!next_token(fp, token, sizeof(token))) { fclose(fp); return NULL; }
    int altura = atoi(token);
    if (!next_token(fp, token, sizeof(token))) { fclose(fp); return NULL; }
    int varmax = atoi(token);

    if (largura <= 0 || altura <= 0 || varmax <= 0) {
        fprintf(stderr, "Cabeçalho PGM inválido\n");
        fclose(fp); return NULL;
    }

    TImagemPGM *img = malloc(sizeof(TImagemPGM));
    if (!img) { perror("malloc"); fclose(fp); return NULL; }
    img->largura = largura;
    img->altura  = altura;
    img->varmax  = varmax;

    size_t npix = (size_t)largura * (size_t)altura;
    img->data = malloc(npix * sizeof(int));
    if (!img->data) { perror("malloc"); free(img); fclose(fp); return NULL; }

    for (size_t i = 0; i < npix; i++) {
        if (!next_token(fp, token, sizeof(token))) {
            fprintf(stderr, "Arquivo PGM truncado\n");
            free(img->data); free(img); fclose(fp); return NULL;
        }
        img->data[i] = atoi(token);
    }

    fclose(fp);
    return img;
}

// Salva PGM (P2 - texto)
void escreverPGM(const char *filename, TImagemPGM *img) {
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("Erro ao salvar arquivo"); return; }
    fprintf(fp, "P2\n%d %d\n%d\n", img->largura, img->altura, img->varmax);
    size_t npix = (size_t)img->largura * (size_t)img->altura;
    for (size_t i = 0; i < npix; i++)
        fprintf(fp, "%d\n", img->data[i]);
    fclose(fp);
}

// Convolução com tratamento de bordas e saturação (clipping em [0, 255])
void convolucao(TImagemPGM *input, TImagemPGM *output, int start_row, int end_row) {
    int largura = input->largura;
    int altura  = input->altura;

    for (int y = start_row; y < end_row; y++) {
        for (int x = 0; x < largura; x++) {
            // Bordas: preserva pixel original sem filtragem
            if (y < MEIO || y >= altura - MEIO ||
                x < MEIO || x >= largura - MEIO) {
                output->data[y * largura + x] = input->data[y * largura + x];
                continue;
            }

            // Soma ponderada (convolução discreta 2D)
            long long sum = 0;
            for (int j = -MEIO; j <= MEIO; j++)
                for (int i = -MEIO; i <= MEIO; i++)
                    sum += (long long)input->data[(y+j) * largura + (x+i)] *
                           (long long)laplaciano[j + MEIO][i + MEIO];

            // Saturação (clipping) conforme especificado no enunciado
            if (sum < 0)   sum = 0;
            if (sum > 255) sum = 255;
            output->data[y * largura + x] = (int)sum;
        }
    }
}

// Função da thread
void *threadFunc(void *arg) {
    ThreadData *td = (ThreadData*) arg;
    convolucao(td->entrada, td->saida, td->linha_inicial, td->linha_final);
    return NULL;
}

// Mede tempo em segundos (clock monotônico, imune a ajustes de NTP/fuso)
double tempo() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

// Função Principal
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Uso: %s <entrada.pgm> <saida.pgm> <num_threads>\n", argv[0]);
        return 1;
    }

    int numero_threads = atoi(argv[3]);
    if (numero_threads <= 0) numero_threads = 1;

    // --- I/O fora da janela de medição ---
    TImagemPGM *input = lerPGM(argv[1]);
    if (!input) return 1;

    TImagemPGM *output = malloc(sizeof(TImagemPGM));
    if (!output) { perror("malloc"); free(input->data); free(input); return 1; }
    output->largura = input->largura;
    output->altura  = input->altura;
    output->varmax  = input->varmax;
    size_t npix = (size_t)input->largura * (size_t)input->altura;
    output->data = malloc(npix * sizeof(int));
    if (!output->data) {
        perror("malloc");
        free(output); free(input->data); free(input);
        return 1;
    }

    if (numero_threads > input->altura)
        numero_threads = input->altura;

    pthread_t  *threads = malloc(numero_threads * sizeof(pthread_t));
    ThreadData *td      = malloc(numero_threads * sizeof(ThreadData));
    if (!threads || !td) {
        perror("malloc");
        free(threads); free(td);
        free(output->data); free(output);
        free(input->data);  free(input);
        return 1;
    }

    int rows_per_thread = input->altura / numero_threads;
    int extra           = input->altura % numero_threads;

    // --- Início da janela de medição (somente convolução) ---
    double inicio = tempo();

    int linha_atual = 0;
    for (int i = 0; i < numero_threads; i++) {
        int linhas = rows_per_thread + (i < extra ? 1 : 0);
        td[i].entrada       = input;
        td[i].saida         = output;
        td[i].linha_inicial = linha_atual;
        td[i].linha_final   = linha_atual + linhas;
        linha_atual        += linhas;

        int rc = pthread_create(&threads[i], NULL, threadFunc, &td[i]);
        if (rc != 0) {
            fprintf(stderr, "Erro pthread_create: %s\n", strerror(rc));
            for (int j = 0; j < i; j++) pthread_join(threads[j], NULL);
            free(threads); free(td);
            free(output->data); free(output);
            free(input->data);  free(input);
            return 1;
        }
    }

    for (int i = 0; i < numero_threads; i++)
        pthread_join(threads[i], NULL);

    double fim = tempo();
    // --- Fim da janela de medição ---

    printf("Tempo (%d threads): %.6f segundos\n", numero_threads, fim - inicio);

    // --- I/O fora da janela de medição ---
    escreverPGM(argv[2], output);

    free(threads);
    free(td);
    free(input->data);  free(input);
    free(output->data); free(output);

    return 0;
}
