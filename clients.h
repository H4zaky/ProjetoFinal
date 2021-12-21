#ifndef PROJETOFINAL_CLIENTS_H
#define PROJETOFINAL_CLIENTS_H

//Mensagens utilizadas para pedir a informação ao cliente.
#define INSERT_CLIENT_CODE_INPUT "Insira o código do cliente:"
#define INSERT_CLIENT_NAME_INPUT "Insira o nome do cliente:"
#define INSERT_CLIENT_NIF_INPUT "Insira o nif do cliente:"
#define INSERT_CLIENT_COUNTRY_INPUT "Insira o país do cliente:"

//Mensagem de erro quando existe o mesmo número repetido.
#define NIF_EXISTS "O número inserido para o nif já existe!"
#define CODE_EXISTS "O número inserido para o código já existe!"


typedef struct {
    int code;
    char *name;
    int nif;
    char *country;
    int removed;
} t_client;

typedef struct {
    t_client *clients;
    int count; // Representa o espaço total ocupado e a posição livre
    int size; // Tamanho total do array
} t_arr_clients;

/**
 * Alloc memory for an array of clients.
 * @return the array of clients.
 */
t_arr_clients *h_clients_alloc();

void h_client_print(const t_client *client);

void h_clients_free(t_arr_clients *clients_arr);

/**
 * Add a new client to the array.
 * @return 1 if successful added, 0 otherwise.
 */
int h_clients_add(t_arr_clients *clients_arr);

/**
 * Finds a client by it's code and marks as removed.
 * @param code the code of the client.
 * @return 1 if found and marked as removed, 0 otherwise.
 */
int h_clients_remove(t_arr_clients *clients_arr, int code);

/**
 * Finds and updates client data.
 * @param code the code of the client.
 * @return 1 if found and successful updated, 0 otherwise
 */
int h_clients_update(t_arr_clients *clients_arr, int code);

/**
 * Iterates the array of clients
 */
void h_clients_list(t_arr_clients *clients_arr);

#endif //PROJETOFINAL_CLIENTS_H
