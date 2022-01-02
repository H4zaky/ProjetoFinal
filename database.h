#ifndef PROJETOFINAL_DATABASE_H
#define PROJETOFINAL_DATABASE_H

#include "clients.h"
#include "orders.h"
#include "articles.h"
#include "utils.h"

#define CLIENTS_DB "CLIENTS.bin"
#define ARTICLES_DB "ARTICLES.bin"
#define ORDERS_DB "ORDERS.bin"

enum STRUCTURE_TYPE {
    CLIENTS, ARTICLES, ORDERS
};

void *h_database_read(enum STRUCTURE_TYPE type);

void h_database_write_clients(const t_clients_arr *clients_arr);

void h_database_write_orders(const t_orders_arr *orders_arr);

void h_database_write_articles(const t_articles_arr *articles_arr);

#endif //PROJETOFINAL_DATABASE_H
