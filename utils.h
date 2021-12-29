#ifndef PROJETOFINAL_UTILS_H
#define PROJETOFINAL_UTILS_H

#define INSERT_PROFILE "Insira o tipo de utilizador:"
#define DATABASE_FILE "DATABASE.bin"
#define FAILED_TO_WRITE "Failed to write"

//Mensagens utilizadas para avisar números repetidos.
#define INVALID_VALUE "O valor inserido é inválido."
#define CODE_EXISTS "O código já existe!"
#define NIF_EXISTS "O nif já existe!"
#define INSERT_OPTION "Insira a opção que deseja:"

//Mensagens utilizadas para os artigos.
#define INSERT_ARTICLE_CODE "Insira o código do artigo:"
#define INSERT_ARTICLE_NAME "Insira um nome para o artigo:"
#define INSERT_ARTICLE_MAX_SIZE "Insira o tamanho máximo:"
#define INSERT_ARTICLE_MIN_SIZE "Insira o tamanho mínimo:"
#define INSERT_ARTICLE_TYPE "Tipo de Sapato:"
#define CODE_INPUT_ARTICLE "Código do Artigo:"
#define ARTICLE_REMOVED_OUTPUT "O artigo foi removido!"

//Mensagens utilizadas para o cliente.
#define INSERT_CLIENT_CODE "Insira o código do cliente:"
#define INSERT_CLIENT_NAME "Insira o nome do cliente:"
#define INSERT_CLIENT_NIF "Insira o nif do cliente:"
#define INSERT_CLIENT_COUNTRY "Insira o país do cliente:"

//Mensagens utilizadas para as encomendas.
#define INSERT_ORDER_CODE "Insira o código da encomenda:"
#define INSERT_BILLING_ADDRESS_ORDER "Insira a morada de faturação:"
#define INSERT_EXPEDITION_ADDRESS_ORDER "Insira a morada de envio:"
#define REMOVE_ORDER_OUTPUT "Encomenda removida com sucesso!"
#define CODE_INPUT_ORDER "Código da encomenda:"

char h_utils_read_char(char *msg);

int h_utils_read_int(int minValor, int maxValor, const char *msg);

float h_utils_read_float(float minValor, float maxValor, char *msg);

void h_utils_read_string(char *string, int tamanho, char *msg);

#endif //PROJETOFINAL_UTILS_H
