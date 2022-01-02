#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "strs.h"

/**
 * A função começa por alocar memória depois verifica se o array de clientes
 * @return
 */
void *h_database_read(enum STRUCTURE_TYPE type) {

    void *ptr;
    FILE *fp;

    t_clients_arr *arr;

    switch (type) {
        case CLIENTS:
            arr = h_clients_alloc();
            fp = fopen(CLIENTS_DB, "rb");
            while ( fread (, sizeof(t_client), 1, arr) != EOF ) {

            }
            //fread(ptr, sizeof(t_clients_arr), 1, fp);
            break;
        case ARTICLES:
            ptr = h_articles_alloc();
            fp = fopen(ARTICLES_DB, "rb");
            break;
        case ORDERS:
            ptr = h_orders_alloc();
            fp = fopen(ORDERS_DB, "rb");
            break;
        default:
            return NULL;
    }

    if (ptr == NULL) {
        free(ptr);
        return NULL;
    }

    if (fp == NULL) {
        printf(DB_NOT_FOUND);
    } else {
        //fread(ptr, sizeof(*ptr), 1, fp);
        fclose(fp);
        printf(SUCCESS_TO_READ);
    }

    return ptr;
}

void h_database_write_clients(const t_clients_arr *clients_arr) {

    FILE *fp = fopen(CLIENTS_DB, "wb");
    if (fp == NULL) {
        fclose(fp);
        printf(FAILED_TO_OPEN_DB_WB);
        return;
    }

    for (int i = 0; i < clients_arr->count; i++) {
        fwrite(&clients_arr->clients[i], sizeof (t_client), 1, fp);

    }

    fclose(fp);
}


void h_database_write_orders(const t_orders_arr *orders_arr) {

    FILE *fp = fopen(ORDERS_DB, "wb");
    if (fp == NULL) {
        fclose(fp);
        printf(FAILED_TO_OPEN_DB_WB);
        return;
    }

    if (fwrite(orders_arr, sizeof(t_orders_arr), 1, fp) != 1) {
        printf(FAILED_TO_WRITE);
    }

    fclose(fp);
}

void h_database_write_articles(const t_articles_arr *articles_arr) {

    FILE *fp = fopen(ARTICLES_DB, "wb");
    if (fp == NULL) {
        fclose(fp);
        printf(FAILED_TO_OPEN_DB_WB);
        return;
    }

    if (fwrite(articles_arr, sizeof(*articles_arr), 1, fp) != 1) {
        printf(FAILED_TO_WRITE);
    }

    fclose(fp);
}
