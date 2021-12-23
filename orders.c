#include "orders.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void collect_order_info(t_orders_arr *orders_arr, int i) {
    // reuse memory
    char *billing_address = orders_arr->orders[i].billing_address;
    char *expedition_address = orders_arr->orders[i].expedition_address;

    h_utils_read_string(billing_address, 64, INSERT_BILLING_ADDRESS_ORDER);
    h_utils_read_string(expedition_address, 64, INSERT_EXPEDITION_ADDRESS_ORDER);

    orders_arr->orders[i].billing_address = billing_address;
    orders_arr->orders[i].expedition_address = expedition_address;
}

void expand_orders_array(t_orders_arr *orders_arr) {
    int new_size;

    new_size = orders_arr->orders_size * 2;

    orders_arr->orders = (t_order *) realloc(orders_arr->orders, new_size * sizeof(t_order));
    if (orders_arr->orders == NULL) {
        perror("Not allocated");
        exit(EXIT_FAILURE);
    }

    orders_arr->orders_size = new_size;

    for (int i = orders_arr->orders_count; i < new_size; i++) {
        orders_arr->orders[i].billing_address = (char *) calloc(64, sizeof(char));
        orders_arr->orders[i].expedition_address = (char *) calloc(64, sizeof(char));
        orders_arr->orders[i].order_code = 0;
        orders_arr->orders[i].order_value = 0.0f;
    }
}

t_orders_arr *h_orders_alloc() {

    t_orders_arr *orders_arr = (t_orders_arr *) malloc(sizeof(t_orders_arr));
    if (orders_arr == NULL) {
        return NULL;
    }

    orders_arr->orders_count = 0;
    orders_arr->orders_size = 20;

    orders_arr->orders = (t_order *) calloc(orders_arr->orders_size, sizeof(t_order));
    if (orders_arr->orders == NULL) {
        return NULL;
    }

    for (int i = 0; i < orders_arr->orders_size; i++) {
        orders_arr->orders[i].billing_address = (char *) calloc(64, sizeof(char));
        orders_arr->orders[i].expedition_address = (char *) calloc(64, sizeof(char));
        orders_arr->orders[i].client_code = 0;
        orders_arr->orders[i].order_code = 0;
        orders_arr->orders[i].order_value = 0.0f;
        orders_arr->orders[i].canceled = 0;
    }

    return orders_arr;
}

void h_orders_free(t_orders_arr *orders_arr) {
    for (int i = 0; i < orders_arr->orders_size; i++) {
        free(orders_arr->orders[i].billing_address);
        free(orders_arr->orders[i].expedition_address);
    }

    free(orders_arr->orders);
    free(orders_arr);
}

int h_orders_add(t_orders_arr *orders_arr, t_clients_arr *clients_arr) {
    int client_code;
    int order_code;

    client_code = h_utils_read_int(0, 9999, INSERT_CLIENT_CODE_INPUT);

    if (h_clients_find_by_code(clients_arr, client_code) == 0) {
        printf("Cliente não existe\n");
        return 0;
    }

    if (orders_arr->orders_count == orders_arr->orders_size) {
        expand_orders_array(orders_arr);
    }

    collect_order_info(orders_arr, orders_arr->orders_count);

    srand(time(NULL));
    order_code = rand() % 9999;

    printf("Código da encomenda: %d\n", order_code);

    orders_arr->orders[orders_arr->orders_count].client_code = client_code;
    orders_arr->orders[orders_arr->orders_count].order_code = order_code;

    orders_arr->orders_count++;

    return 1;
}

int h_orders_cancel(t_orders_arr *orders_arr) {
    int order_code;

    order_code = h_utils_read_int(0, 9999, INSERT_ORDER_CODE);

    for (int i = 0; i < orders_arr->orders_count; i++) {
        if (orders_arr->orders[i].order_code == order_code) {
            orders_arr->orders[i].canceled = 1;
            return 1;
        }
    }

    return 0;
}

int h_orders_update(t_orders_arr *orders_arr) {
    int order_code;

    order_code = h_utils_read_int(0, 9999, INSERT_ORDER_CODE);

    for (int i = 0; i < orders_arr->orders_count; i++) {
        if (orders_arr->orders[i].order_code == order_code) {
            collect_order_info(orders_arr, i);
        }
    }

    return 0;
}

void h_order_print(t_order *order) {
    printf("Código do cliente: %d\n", order->client_code);
    printf("Código da encomenda: %d\n", order->order_code);
    printf("Morada de envio: %s\n", order->expedition_address);
    printf("Morada de faturação: %s\n", order->billing_address);
    printf("Valor da encomenda: %f\n", order->order_value);

    if (order->canceled) {
        printf("Estado da encomenda: CANCELADO\n");
    }
}

void h_orders_list_mine(t_orders_arr *orders_arr) {

    if (orders_arr->orders_count == 0) {
        printf("Vazio");
        return;
    }

    int client_code = h_utils_read_int(0, 9999, INSERT_CLIENT_CODE_INPUT);

    for (int i = 0; i < orders_arr->orders_count; i++) {
        if (orders_arr->orders[i].client_code == client_code) {
            h_order_print(&orders_arr->orders[i]);
        }
    }
}

void h_orders_list_all(t_orders_arr *orders_arr) {

    if (orders_arr->orders_count == 0) {
        printf("Vazio\n");
        return;
    }

    for (int i = 0; i < orders_arr->orders_count; i++) {
        h_order_print(&orders_arr->orders[i]);
    }
}

void h_orders_list_canceled(t_orders_arr *orders_arr) {

    if (orders_arr->orders_count == 0) {
        printf("Vazio\n");
        return;
    }

    for (int i = 0; i < orders_arr->orders_count; i++) {
        if (orders_arr->orders[i].canceled == 1) {
            h_order_print(&orders_arr->orders[i]);
        }
    }
}

