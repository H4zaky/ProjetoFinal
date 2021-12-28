#ifndef PROJETOFINAL_UTILS_H
#define PROJETOFINAL_UTILS_H

//Mensagem utilizada para informar sobre o valor inválido.
#define VALOR_INVALIDO "O valor inserido é inválido."
#define CODE_EXISTS "O número inserido para o código já existe!"

//Mensagem utilizada para pedir a opção dentro dos menus.
#define INSERT_OPTION_INPUT "Insira a opção que deseja:"

//Mensagem utilizada para pedir o tipo de utilizador.
#define INSERT_PROFILE_INPUT "Insira o tipo de utilizador:"

char h_utils_read_char(char *msg);

int h_utils_read_int(int minValor, int maxValor, const char *msg);

float h_utils_read_float(float minValor, float maxValor, char *msg);

void h_utils_read_string(char *string, int tamanho, char *msg);

#endif //PROJETOFINAL_UTILS_H
