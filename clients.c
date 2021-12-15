#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "clients.h"
#include "utils.h"

int find_code(t_arr_clients *clients_arr, int code);

int find_nif(t_arr_clients *clients_arr, int nif);

int read_client(t_arr_clients *client_arr, int i) {
    int code, nif;

    // reuse memory
    char *name = client_arr->clients[i].name;
    char *country =  client_arr->clients[i].country;

    code = h_utils_read_int(0, 9999, CODE_INPUT);
    if (find_code(client_arr, code)) {
        printf(CODE_EXISTS);
        return 0;
    }

    h_utils_read_string(name, 64, NAME_INPUT);

    nif = h_utils_read_int(99999999, 999999999, NIF_INPUT);
    if (find_nif(client_arr, nif)) {
        printf(NIF_EXISTS);
        return 0;
    }

    h_utils_read_string(country, 3, COUNTRY_INPUT);

    client_arr->clients[i].code = code;
    client_arr->clients[i].name = name;
    client_arr->clients[i].nif = nif;
    client_arr->clients[i].country = country;

    return 1;
}

//Linear search
int find_code(t_arr_clients *clients_arr, int code) {
    for (int i = 0; i < clients_arr->count; i++) {
        if (clients_arr->clients[i].code == code) {
            return 1;
        }
    }
    return 0;
}

//Linear search
int find_nif(t_arr_clients *clients_arr, int nif) {
    for (int i = 0; i < clients_arr->count; i++) {
        if (clients_arr->clients[i].nif == nif) {
            return 1;
        }
    }
    return 0;
}

void expand_array(t_arr_clients *clients_arr) {
    int new_size;

    new_size = clients_arr->size * 2;

    clients_arr->clients = (t_client *) realloc(clients_arr->clients, new_size * sizeof(t_client));
    if (clients_arr->clients == NULL) {
        printf("Não alocou!");
        exit(1);
    }

    clients_arr->size = new_size;

    for (int i = clients_arr->count; i < new_size; i++) {
        clients_arr->clients[i].name = (char *) calloc(64, sizeof(char));
        clients_arr->clients[i].country = (char *) calloc(3, sizeof(char));
        clients_arr->clients[i].removed = 0;
        clients_arr->clients[i].code = 0;
        clients_arr->clients[i].nif = 0;
    }
}

t_arr_clients *h_clients_alloc() {

    t_arr_clients *clients_arr = (t_arr_clients *) malloc(sizeof(t_arr_clients));
    if (clients_arr == NULL) {
        return NULL;
    }

    clients_arr->count = 0;
    clients_arr->size = 1;

    clients_arr->clients = (t_client *) calloc(clients_arr->size, sizeof(t_client));
    if (clients_arr->clients == NULL) {
        return NULL;
    }

    for (int i = 0; i < clients_arr->size; i++) {
        clients_arr->clients[i].name = (char *) calloc(64, sizeof(char));
        clients_arr->clients[i].country = (char *) calloc(3, sizeof(char));
    }

    return clients_arr;
}

void h_clients_free(t_arr_clients *clients_arr) {
    for (int i = 0; i < clients_arr->size; i++) {
        free(clients_arr->clients[i].name);
        free(clients_arr->clients[i].country);
    }

    free(clients_arr->clients);
    free(clients_arr);
}

int h_clients_add(t_arr_clients *clients_arr) {

    if (clients_arr == NULL) {
        return 0;
    }

    if (clients_arr->count == clients_arr->size) {
        expand_array(clients_arr);
    }

    if (read_client(clients_arr, clients_arr->count) != 1) {
        return 0;
    }

    clients_arr->count++;

    return 1;
}

int h_clients_remove(t_arr_clients *clients_arr, int code) {
    for (int i = 0; i < clients_arr->count; ++i) {
        if (clients_arr->clients[i].code == code) {
            clients_arr->clients[i].removed = 1;
            return 1;
        }
    }

    return 0;
}

int h_clients_update(t_arr_clients *clients_arr, int code) {
    for (int i = 0; i < clients_arr->count; ++i) {
        if (clients_arr->clients[i].code == code) {
            return read_client(clients_arr, i);
        }
    }

    return 0;
}

void h_clients_list(t_arr_clients *clients_arr) {
    for (int i = 0; i < clients_arr->count; ++i) {
        printf("\n----\n");
        printf("Código de cliente: %d\n", clients_arr->clients[i].code);
        printf("Nome do Cliente: %s\n", clients_arr->clients[i].name);
        printf("Nif do cliente: %d\n", clients_arr->clients[i].nif);
        printf("País do cliente: %s\n", clients_arr->clients[i].country);
        printf("Removido: %d", clients_arr->clients[i].removed);
        printf("\n----\n");
        printf("teste";)
    }
}


