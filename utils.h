//
// Created by Carlo on 13/12/2021.
//

#ifndef PROJETOFINAL_UTILS_H
#define PROJETOFINAL_UTILS_H

#define VALOR_INVALIDO "O valor inserido é inválido."
#define INSERT_OPTION_INPUT "Insira a opção que deseja:"
#define INSERT_CODE_INPUT "Insira o código do cliente:"

char h_utils_read_char(char *msg);

int h_utils_read_int(int minValor, int maxValor, char *msg);

float h_utils_read_float(float minValor, float maxValor, char *msg);

void h_utils_read_string(char *string, int tamanho, char *msg);

#endif //PROJETOFINAL_UTILS_H
