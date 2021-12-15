#include <stdio.h>

#include "clients.h"

int main() {

    t_arr_clients *clients_arr = NULL;

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        return 1;
    }

    h_clients_add(clients_arr);
    h_clients_add(clients_arr);

    h_clients_list(clients_arr);

    h_clients_free(clients_arr);

    return 0;
}
