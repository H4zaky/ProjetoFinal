#ifndef PROJETOFINAL_CLIENTS_H
#define PROJETOFINAL_CLIENTS_H

#define CODE_INPUT "Código do cliente: "
#define NAME_INPUT "Nome do Cliente: "

typedef struct {
    int code;
    char *name;
    int nif;
    char *country;
    int removed;
} t_client;

typedef struct {
    t_client *clients;
    int count; // Represents the total used space and the free position
    int size; // Array total size
} t_arr_clients;

/**
 * Alloc memory for an array of clients
 * @return the array of clients
 */
t_arr_clients *h_clients_alloc();

/**
 * Add a new client to the array.
 * @return 1 if successful added, 0 otherwise.
 */
int h_clients_add();

/**
 * Finds a client by it's code and marks as removed.
 * @param code the code of the client.
 * @return 1 if found and marked as removed, 0 otherwise.
 */
int h_clients_remove(int code);

/**
 * Finds and updates client data.
 * @param code the code of the client.
 * @return 1 if found and successful updated, 0 otherwise
 */
int h_clients_update(int code);

/**
 * Iterates the array of clients
 */
void h_clients_list();

#endif //PROJETOFINAL_CLIENTS_H
