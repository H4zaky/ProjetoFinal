#include <malloc.h>
#include <stdio.h>
#include "clients.h"


t_arr_clients *h_clients_alloc() {

    t_arr_clients *clients_arr = (t_arr_clients *) calloc(1, sizeof(t_arr_clients));
    if (clients_arr == NULL) {
        return NULL;
    }

    // Inicializa 20 estruturas do tipo t_client a 0
    clients_arr->clients = (t_client *) calloc(20, sizeof(t_client));
    if (clients_arr->clients == NULL) {
        return NULL;
    }

    clients_arr->count = 0;
    clients_arr->size = 20;

    return clients_arr;
}

int h_clients_add(t_arr_clients* clients_arr) {

    printf(CODE_INPUT);
    scanf("%d", &clients_arr->clients[clients_arr->count].code);

    printf(NAME_INPUT);
    //scanf("");

    clients_arr->count++;


    return 0;
}


