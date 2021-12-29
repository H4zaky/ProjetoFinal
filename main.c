#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articles.h"
#include "clients.h"
#include "orders.h"
#include "menus.h"

int main() {

    t_clients_arr *clients_arr = NULL;
    t_articles_arr *articles_arr = NULL;
    t_orders_arr *orders_arr = NULL;
    if() {

    }
    articles_arr = h_articles_alloc();
    if (articles_arr == NULL) {
        perror("Articles Exit\n");
        return 1;
    }

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        free(articles_arr);
        perror("Clients Exited\n");
        return 1;
    }

    orders_arr = h_orders_alloc();
    if (orders_arr == NULL) {
        free(articles_arr);
        free(clients_arr);
        perror("Orders Exited\n");
        return 1;
    }

    h_menus_profile(clients_arr, articles_arr, orders_arr);

    h_clients_free(clients_arr);
    h_articles_free(articles_arr);
    h_orders_free(orders_arr);

    return 0;
}
