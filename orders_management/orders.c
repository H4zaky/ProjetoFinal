#include "orders.h"
#include <stdlib.h>
#include <stdio.h>

int find_orders_code(t_orders_arr *orders_arr, int orders_code);

int find_orders_code(t_orders_arr *orders_arr, int orders_code) {
    for (int i = 0; i < orders_arr->orders_count; i++) {
        if (orders_arr->orders[i].order_code == orders_code) {
            return 1;
        }
    }
    return 0;
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
        orders_arr->orders[i].expedition_address = (char *) calloc(64, sizeof (char));
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
        orders_arr->orders[i].expedition_address = (char *) calloc(64, sizeof (char));
        orders_arr->orders[i].order_code = 0;
        orders_arr->orders[i].order_value = 0.0f;
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

int h_orders_add(t_orders_arr *orders_arr) {

    if (orders_arr == NULL) {
        return 0;
    }

    if (orders_arr->orders_count == orders_arr->orders_size) {
        expand_orders_array(orders_arr);
    }

    // TODO

    orders_arr->orders_count++;

    return 1;
}
