#include <stdio.h>

#include "clients.h"

int main() {

    t_arr_clients* clients_arr = NULL;

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        return 1;
    }

    printf("Size: %d", clients_arr->size);

    return 0;
}
