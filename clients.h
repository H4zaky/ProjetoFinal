#ifndef PROJETOFINAL_CLIENTS_H
#define PROJETOFINAL_CLIENTS_H

#include "utils.h"

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
} t_clients_arr;

/**
 * Alloc memory for an array of clients.
 * @return the array of clients.
 */
t_clients_arr *h_clients_alloc();

int h_clients_find_by_code(t_clients_arr *clients_arr, int code);

void h_client_print(const t_client *client);

void h_clients_free(t_clients_arr *clients_arr);

/**
 * Add a new client to the array.
 * @return 1 if successful added, 0 otherwise.
 */
int h_clients_add(t_clients_arr *clients_arr);

/**
 * Finds a client by it's code and marks as removed.
 * @param code the code of the client.
 * @return 1 if found and marked as removed, 0 otherwise.
 */
void h_clients_remove(t_clients_arr *clients_arr, int code);

/**
 * Finds and updates client data.
 * @param code the code of the client.
 * @return 1 if found and successful updated, 0 otherwise
 */
void h_clients_update(t_clients_arr *clients_arr, int code);

/**
 * Iterates the array of clients
 */
void h_clients_list(t_clients_arr *clients_arr);

#endif //PROJETOFINAL_CLIENTS_H
