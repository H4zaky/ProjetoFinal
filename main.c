#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articles.h"
#include "clients.h"
#include "orders.h"
#include "menus.h"

int main() {

    t_articles_arr *articles_arr = NULL;
    t_clients_arr *clients_arr = NULL;
    t_orders_arr *orders_arr = NULL;

    articles_arr = (t_articles_arr *) h_database_read(ARTICLES);
    if (articles_arr == NULL) {
        perror("Articles Exit\n");
        return 1;
    }

    clients_arr = (t_clients_arr*) h_database_read(CLIENTS);
    if (clients_arr == NULL) {
        free(articles_arr);
        perror("Clients Exited\n");
        return 1;
    }
    printf("%d", clients_arr->count);
    printf("%d", clients_arr->size);

    orders_arr = (t_orders_arr*) h_database_read(ORDERS);
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
