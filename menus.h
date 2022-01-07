/**
 * @file menus.h
 * @author Carlos Leite
 * @date 07/01/2022
 * @brief Menus
 */

#ifndef PROJETOFINAL_MENUS_H
#define PROJETOFINAL_MENUS_H

#include "clients.h"
#include "articles.h"
#include "orders.h"
#include "utils.h"
#include "costs.h"

/**
 * Menu de seleção de utilizador.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_profile(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades do admin.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades do cliente.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_client(t_clients_arr *clients_arr,  t_articles_arr *articles_arr, t_orders_arr *orders_arr);

// Admin specific menus
/**
 * Menu com as funcionalidades de criar do admin.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin_create(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades de update do admin.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin_update(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades de remover do admin.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin_remove(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades de listar do admin
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin_list(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

/**
 * Menu com as funcionalidades de gravar/guardar informações.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_admin_database(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

// Client specific menus
/**
 * Menu com as as funcionalidades sobre as encomendas do cliente.
 * @param clients_arr
 * @param articles_arr
 * @param orders_arr
 */
void h_menus_client_orders(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

#endif //PROJETOFINAL_MENUS_H
