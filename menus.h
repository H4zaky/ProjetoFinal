/**
 * @file menus.h
 * @author
 * @date
 * @brief Menus
 */

#ifndef PROJETOFINAL_MENUS_H
#define PROJETOFINAL_MENUS_H

#include "clients.h"
#include "articles.h"
#include "orders.h"
#include "utils.h"
#include "costs.h"

void h_menus_profile(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_admin(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_client(t_clients_arr *clients_arr,  t_articles_arr *articles_arr, t_orders_arr *orders_arr);

// Admin specific menus
void h_menus_admin_create(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr, t_costs *costs);

void h_menus_admin_update(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_admin_remove(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_admin_list(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_admin_database(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

// Client specific menus
void h_menus_client_orders(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

#endif //PROJETOFINAL_MENUS_H
