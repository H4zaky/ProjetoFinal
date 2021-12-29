#ifndef PROJETOFINAL_DATABASE_H
#define PROJETOFINAL_DATABASE_H

#include "clients.h"
#include "orders.h"
#include "articles.h"
#include "utils.h"



void h_database_write_clients(const t_clients_arr *clients_arr);

t_clients_arr *h_database_read_clients();

void h_database_write_orders(const t_orders_arr *orders_arr);

t_orders_arr *h_database_read_orders();

void h_database_write_articles(const t_articles_arr *articles_arr);

t_articles_arr *h_database_read_articles();

#endif //PROJETOFINAL_DATABASE_H
