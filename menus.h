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

void h_menus_profile();

void h_menus_admin(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void h_menus_client();

// Admin specific menus

void h_menus_admin_create();

void h_menus_admin_update();

void h_menus_admin_remove();

void h_menus_admin_list();

void h_menus_admin_database();

// Client specific menus

void h_menus_client_orders();


#endif //PROJETOFINAL_MENUS_H