#include "orders.h"
#include "costs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void collect_item_info(t_order *order, t_articles_arr *articles_arr, t_costs *costs) {
    int op;
    int article_code;
    int items_quantity;
    int found = 0;
    int shoe_size;
    float item_cost;
    t_article *article = NULL;

    do {
        op = h_utils_read_int(0, 1, INSERT_OPTION_BUY);
        if (op == 1) {
            if (order->items_count == order->items_size) {
                expand_items_arr(order);
            }

            items_quantity = h_utils_read_int(1, 10, INSERT_QUANTITY_SIZE);

            do {
                article_code = h_utils_read_int(0, 9999, INSERT_ARTICLE_CODE);
                if ((article = find_article_by_code(articles_arr, article_code)) == NULL) {
                    printf("Artigo não existe!\n");
                } else {
                    found = 1;
                    shoe_size = h_utils_read_int(article->min_size, article->max_size, INSERT_FOOTWEAR_SIZE);
                    item_cost = h_calculate_shoe_cost(article->type, shoe_size, costs);
                    printf("Cost Unit %f", item_cost);
                }
            } while (found == 0);

            order->items_arr[order->items_count].article_code = article_code;
            order->items_arr[order->items_count].quantity = items_quantity;
            order->items_arr[order->items_count].cost = item_cost * (float) items_quantity;
            order->order_value += order->items_arr[order->items_count].cost;

            printf("Numero de artigos: %d\n", items_quantity);
            printf("Custo total do artigo: %0.1f\n", order->items_arr[order->items_count].cost);

            order->items_count++;
        }
    } while (op != 0);

    printf("Custo total da encomenda: %f\n", order->order_value);
}

void collect_order_info(t_orders_arr *orders_arr, int i) {
    // reuse memory
    char *billing_address = orders_arr->orders[i].billing_address;
    char *expedition_address = orders_arr->orders[i].expedition_address;

    h_utils_read_string(billing_address, 64, INSERT_BILLING_ADDRESS_ORDER);
    h_utils_read_string(expedition_address, 64, INSERT_EXPEDITION_ADDRESS_ORDER);

    orders_arr->orders[i].billing_address = billing_address;
    orders_arr->orders[i].expedition_address = expedition_address;
}

void expand_items_arr(t_order *order) {

    order->items_size *= 2;

    order->items_arr = (t_item *) realloc(order->items_arr,
                                         order->items_size * sizeof(t_item));

    if (order->items_arr == NULL) {
        perror("Not allocated\n");
        exit(EXIT_FAILURE);
    }

    for (int j = order->items_count; j < order->items_size; j++) {
        order->items_arr[j].cost = 0.0f;
        order->items_arr[j].quantity = 0;
        order->items_arr[j].article_code = 0;
    }
}

void expand_orders_arr(t_orders_arr *orders_arr) {
    int new_order_size;

    new_order_size = orders_arr->orders_size * 2;

    orders_arr->orders = (t_order *) realloc(orders_arr->orders, new_order_size * sizeof(t_order));
    if (orders_arr->orders == NULL) {
        perror("Not allocated\n");
        exit(EXIT_FAILURE);
    }

    orders_arr->orders_size = new_order_size;

    for (int i = orders_arr->orders_count; i < new_order_size; i++) {
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
        if (orders_arr->orders[i].billing_address == NULL) {
            return NULL;
        }

        orders_arr->orders[i].expedition_address = (char *) calloc(64, sizeof(char));
        if (orders_arr->orders[i].expedition_address == NULL) {
            return NULL;
        }

        orders_arr->orders[i].client_code = 0;
        orders_arr->orders[i].order_code = 0;
        orders_arr->orders[i].order_value = 0.0f;
        orders_arr->orders[i].canceled = 0;

        orders_arr->orders[i].items_count = 0;
        orders_arr->orders[i].items_size = 10;
        orders_arr->orders[i].items_arr = (t_item *) calloc(orders_arr->orders[i].items_size,
                                                            sizeof(t_item));
        if (orders_arr->orders[i].items_arr == NULL) {
            return NULL;
        }
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

int h_orders_add(t_orders_arr *orders_arr, t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_costs *costs) {
    int client_code;
    int order_code;

    client_code = h_utils_read_int(0, 9999, INSERT_CLIENT_CODE);
    if (h_clients_find_by_code(clients_arr, client_code) == 0) {
        printf("Cliente não existe\n");
        return 0;
    }

    if (orders_arr->orders_count == orders_arr->orders_size) {
        expand_orders_arr(orders_arr);
    }

    collect_order_info(orders_arr, orders_arr->orders_count);
    collect_item_info(&orders_arr->orders[orders_arr->orders_count],
                      articles_arr,
                      costs);

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

    int client_code = h_utils_read_int(0, 9999, INSERT_CLIENT_CODE);

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


