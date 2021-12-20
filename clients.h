#ifndef PROJETOFINAL_CLIENTS_H
#define PROJETOFINAL_CLIENTS_H

#define CODE_INPUT_CLIENT "Código do Cliente:"
#define NAME_INPUT_CLIENT "Nome do Cliente:"
#define NIF_INPUT_CLIENT "Nif do Cliente:"
#define COUNTRY_INPUT_CLIENT "País do Cliente:"

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

void cleanInputBuffer();

char obterChar(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

#endif //PROJETOFINAL_CLIENTS_H
