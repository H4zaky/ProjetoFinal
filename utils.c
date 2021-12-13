#include <stdio.h>
#include <string.h>
#include "utils.h"

#define VALOR_INVALIDO "O valor inserido é inválido."

void clean_input_buffer() {
    char ch;
    while ((ch = (char) getchar()) != '\n' && ch != EOF);
}

char h_utils_read_char(char *msg) {
    char valor;
    printf("%s", msg);
    valor = (char) getchar();
    clean_input_buffer();
    return valor;
}

int h_utils_read_int(int minValor, int maxValor, char *msg) {
    int valor;
    printf("%s", msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        clean_input_buffer();
        printf("%s", msg);
    }
    clean_input_buffer();
    return valor;
}

void h_utils_read_string(char *string, int tamanho, char *msg) {
    printf("%s", msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            clean_input_buffer();
        }
    }
}
