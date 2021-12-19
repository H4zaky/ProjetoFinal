#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "clients.h"


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

float h_utils_read_float(float minValor, float maxValor, char *msg) {
    float valor;
    printf("%s", msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
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
