#ifndef PROJETOFINAL_ORDERS_H
#define PROJETOFINAL_ORDERS_H

#include <bits/types/time_t.h>
#include "../utils.h"

#define CODE_INPUT_ORDER "Código da encomenda:"

typedef struct {
    char *expedition_address;
    char *billing_address;
    float order_value;
    int order_code;
    time_t order_time;
} t_order;

typedef struct {
    t_order* orders;
    int orders_count;
    int orders_size;
} t_orders_arr;

t_orders_arr *h_orders_alloc();

void h_orders_free(t_orders_arr *orders_arr);

int h_orders_update(int order_code);

/**
 * Admin / Client
 */
void h_orders_cancel();

/**
 * Client / Admin
 */
void h_orders_list();

/**
 * Admin
 */
void h_orders_list_all();

/**
 * Extra (Admin)
 */
void h_orders_list_canceled();

#endif //PROJETOFINAL_ORDERS_H
