#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "clients.h"
#include "utils.h"

int find_nif(t_clients_arr *clients_arr, int nif);

int is_empty(const t_clients_arr *clients_arr);

int read_client(t_clients_arr *client_arr, int i) {
    int code, nif;

    // reuse memory
    char *name = client_arr->clients[i].name;
    char *country = client_arr->clients[i].country;

    code = h_utils_read_int(0, 9999, INSERT_CLIENT_CODE_INPUT);
    if (h_clients_find_by_code(client_arr, code)) {
        printf(CODE_EXISTS);
        return 0;
    }

    h_utils_read_string(name, 64, INSERT_CLIENT_NAME_INPUT);

    nif = h_utils_read_int(99999999, 999999999, INSERT_CLIENT_NIF_INPUT);
    if (find_nif(client_arr, nif)) {
        printf(NIF_EXISTS);
        return 0;
    }

    h_utils_read_string(country, 3, INSERT_CLIENT_COUNTRY_INPUT);

    client_arr->clients[i].code = code;
    client_arr->clients[i].name = name;
    client_arr->clients[i].nif = nif;
    client_arr->clients[i].country = country;

    return 1;
}

//Linear search
int h_clients_find_by_code(t_clients_arr *clients_arr, int code) {
    for (int i = 0; i < clients_arr->count; i++) {
        if (clients_arr->clients[i].code == code) {
            return 1;
        }
    }
    return 0;
}

//Linear search
int find_nif(t_clients_arr *clients_arr, int nif) {
    for (int i = 0; i < clients_arr->count; i++) {
        if (clients_arr->clients[i].nif == nif) {
            return 1;
        }
    }
    return 0;
}

void expand_clients_array(t_clients_arr *clients_arr) {
    int new_size;

    new_size = clients_arr->size * 2;

    clients_arr->clients = (t_client *) realloc(clients_arr->clients, new_size * sizeof(t_client));
    if (clients_arr->clients == NULL) {
        printf("Não alocou!");
        exit(1);
    }

    clients_arr->size = new_size;

    for (int i = clients_arr->count; i < clients_arr->size; i++) {
        clients_arr->clients[i].name = (char *) calloc(64, sizeof(char));
        clients_arr->clients[i].country = (char *) calloc(3, sizeof(char));
        clients_arr->clients[i].removed = 0;
        clients_arr->clients[i].code = 0;
        clients_arr->clients[i].nif = 0;
    }
}

t_clients_arr *h_clients_alloc() {

    t_clients_arr *clients_arr = (t_clients_arr *) malloc(sizeof(t_clients_arr));
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

void h_clients_free(t_clients_arr *clients_arr) {
    for (int i = 0; i < clients_arr->size; i++) {
        free(clients_arr->clients[i].name);
        free(clients_arr->clients[i].country);
    }

    free(clients_arr->clients);
    free(clients_arr);
}

int h_clients_add(t_clients_arr *clients_arr) {

    if (clients_arr == NULL) {
        return 0;
    }

    if (clients_arr->count == clients_arr->size) {
        expand_clients_array(clients_arr);
    }

    if (read_client(clients_arr, clients_arr->count) != 1) {
        return 0;
    }

    clients_arr->count++;

    return 1;
}

void h_clients_remove(t_clients_arr *clients_arr, int code) {

    if (is_empty(clients_arr)) {
        return;
    }


    for (int i = 0; i < clients_arr->count; ++i) {
        if (clients_arr->clients[i].code == code) {
            clients_arr->clients[i].removed = 1;

            printf("Removido com sucesso");
            return;
        }
    }

    printf("Não foi removido!");
}

void h_clients_update(t_clients_arr *clients_arr, int code) {

    if (is_empty(clients_arr)) {
        return;
    }

    for (int i = 0; i < clients_arr->count; i++) {
        if (clients_arr->clients[i].code == code) {

            if (read_client(clients_arr, i)) {
                printf("Atualizado com sucesso!");
                return;
            }
        }
    }

    printf("Não Atualizado!");
}

void h_clients_list(t_clients_arr *clients_arr) {

    if (is_empty(clients_arr)) {
        return;
    }

    for (int i = 0; i < clients_arr->count; ++i) {
        h_client_print(&clients_arr->clients[i]);
    }
}

int is_empty(const t_clients_arr *clients_arr) {
    if (clients_arr->count == 0) {
        printf("Não existem clientes a listar!\n");
        return 1;
    }

    return 0;
}

void h_client_print(const t_client *client) {
    printf("\n----\n");
    printf("Código de cliente: %d\n", client->code);
    printf("Nome do Cliente: %s\n", client->name);
    printf("Nif do cliente: %d\n", client->nif);
    printf("País do cliente: %s\n", client->country);
    printf("Removido: %d", client->removed);
    printf("\n----\n");
}


