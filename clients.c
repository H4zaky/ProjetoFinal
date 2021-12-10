#include <malloc.h>
#include <stdio.h>
#include "clients.h"

t_arr_clients *h_clients_alloc() {

    t_arr_clients *clients_arr = (t_arr_clients *) malloc(sizeof(t_arr_clients));
    if (clients_arr == NULL) {
        return NULL;
    }

    clients_arr->count = 0;
    clients_arr->size = 20;

    // Inicializa 20 estruturas do tipo t_client a 0
    clients_arr->clients = (t_client *) calloc(20, sizeof(t_client));
    if (clients_arr->clients == NULL) {
        return NULL;
    }

    for (int i = 0; i < clients_arr->size; i++) {
        clients_arr->clients[i].name = (char *) calloc(64, sizeof(char));
        clients_arr->clients[i].nif = (char *) calloc(9, sizeof(char));
        clients_arr->clients[i].country = (char *) calloc(64, sizeof(char));
    }

    return clients_arr;
}

void h_clients_free(t_arr_clients *clients_arr) {
    for (int i = 0; i < clients_arr->size; i++) {
        free(clients_arr->clients[i].name);
        free(clients_arr->clients[i].nif);
        free(clients_arr->clients[i].country);
    }

    free(clients_arr->clients);
    free(clients_arr);
}

int h_clients_add(t_arr_clients *clients_arr) {

    if (clients_arr == NULL) {
        return 0;
    }

    printf(CODE_INPUT);
    scanf("%d", &clients_arr->clients[clients_arr->count].code);

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

            // TODO Alterar dados
            return 1;
        }
    }

    return 0;
}

void h_clients_list(t_arr_clients *clients_arr) {
    for (int i = 0; i < clients_arr->count; ++i) {
        printf("\n----\n");
        printf("Código de cliente: %d\n", clients_arr->clients[i].code);
        printf("Removido: %d", clients_arr->clients[i].removed);
        printf("\n----");
    }

}


