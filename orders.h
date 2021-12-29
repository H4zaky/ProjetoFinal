#ifndef PROJETOFINAL_ORDERS_H
#define PROJETOFINAL_ORDERS_H

#include <bits/types/time_t.h>
#include "utils.h"
#include "clients.h"



typedef struct {
    char *expedition_address;
    char *billing_address;
    float order_value;
    int order_code;
    int client_code;
    int canceled;
} t_order;

typedef struct {
    t_order* orders;
    int orders_count;
    int orders_size;
} t_orders_arr;

t_orders_arr *h_orders_alloc();

void h_orders_free(t_orders_arr *orders_arr);

int h_orders_add(t_orders_arr *orders_arr, t_clients_arr *clients_arr);

int h_orders_update(t_orders_arr *t_orders_arr);

/**
 * Admin / Client
 */
int h_orders_cancel(t_orders_arr *orders_arr);

void h_order_print(t_order *order);

/**
 * Client / Admin
 */
void h_orders_list_mine(t_orders_arr *orders_arr);

/**
 * Admin
 */
void h_orders_list_all(t_orders_arr *orders_arr);

/**
 * Extra (Admin)
 */
void h_orders_list_canceled(t_orders_arr *orders_arr);

#endif //PROJETOFINAL_ORDERS_H
