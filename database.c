#include <stdio.h>
#include <stdlib.h>
#include "database.h"

FILE *open_database(const char *mode);

void h_database_write_clients(const t_clients_arr *clients_arr) {

    FILE *fp = open_database("wb");

    if (fwrite(clients_arr, sizeof(t_clients_arr), 1, fp) != 1) {
        printf(FAILED_TO_WRITE);
    }

    fclose(fp);
}

t_clients_arr *h_database_read_clients() {

    FILE *fp = open_database("rb");

    t_clients_arr *clients_arr = h_clients_alloc();

    if (fread(clients_arr, sizeof(*clients_arr), 1, fp) != 1) {
        fclose(fp);
        free(clients_arr);
        return NULL;
    }

    h_clients_list(clients_arr);

    fclose(fp);

    return clients_arr;
}

void h_database_write_orders(const t_orders_arr *orders_arr) {

    FILE *fp = open_database("wb");

    if (fwrite(orders_arr, sizeof(t_orders_arr), 1, fp) != 1) {
        printf(FAILED_TO_WRITE);
    }

    fclose(fp);
}

t_orders_arr *h_database_read_orders() {

    FILE *fp = open_database("rb");

    t_orders_arr *orders_arr = h_orders_alloc();

    if (fread(orders_arr, sizeof(*orders_arr), 1, fp) != 1) {
        fclose(fp);
        free(orders_arr);
        return NULL;
    }

    h_orders_list_all(orders_arr);

    fclose(fp);

    return orders_arr;
}

void h_database_write_articles(const t_articles_arr *articles_arr) {

    FILE *fp = open_database("wb");

    if (fwrite(articles_arr, sizeof(*articles_arr), 1, fp) != 1) {
        printf(FAILED_TO_WRITE);
    }

    fclose(fp);
}

t_articles_arr *h_database_read_articles() {

    FILE *fp = open_database("rb");

    t_articles_arr *articles_arr = h_articles_alloc();

    if (fread(articles_arr, sizeof(*articles_arr), 1, fp) != 1) {
        fclose(fp);
        free(articles_arr);
        return NULL;
    }

    h_articles_list(articles_arr);

    fclose(fp);

    return articles_arr;
}

FILE *open_database(const char *mode) {
    FILE *fp = fopen(DATABASE_FILE, mode);
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    return fp;
}
