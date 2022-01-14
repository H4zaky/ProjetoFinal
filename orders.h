/**
 * @file orders.h
 * @author Carlos Leite
 * @date 07/01/2022
 * @brief Orders
 */

#ifndef PROJETOFINAL_ORDERS_H
#define PROJETOFINAL_ORDERS_H

#include <bits/types/time_t.h>
#include "utils.h"
#include "clients.h"
#include "articles.h"
#include "costs.h"

typedef struct {
    int article_code;
    int quantity;
    float cost;
} t_item;

typedef struct {
    char *expedition_address;
    char *billing_address;
    float order_value;
    int order_code;
    int client_code;
    int canceled;
    t_item *items_arr;
    int items_size;
    int items_count;
} t_order;

typedef struct {
    t_order *orders;
    int orders_count;
    int orders_size;
} t_orders_arr;


void expand_items_arr(t_order *order);

void expand_orders_arr(t_orders_arr *orders_arr);

/**
 * Alloca memória para o array de encomendas.
 * @return um array de encomendas.
 */
t_orders_arr *h_orders_alloc();

/**
 * Função para libertar a memória do array de encomendas.
 * @param orders_arr
 */
void h_orders_free(t_orders_arr *orders_arr);

/**
 * Adiciona uma encomenda ao array.
 * @param orders_arr
 * @param clients_arr
 * @return 1 se adicionado com sucesso, caso-contrário 0.
 */
int h_orders_add(t_orders_arr *orders_arr, t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_costs *costs);

/**
 * Atualiza as informações da encomenda.
 * @param t_orders_arr
 * @return 1 se encontrado e atualizado, caso-contrário 0.
 */
int h_orders_update(t_orders_arr *t_orders_arr);

/**
 * A função pede ao utilizador o código da encomenda, percorre o array para procurar a encomenda
 * com esse código e remove.
 * @param orders_arr
 * @return 1 se removido com sucesso, caso-contrário 0.
 */
int h_orders_cancel(t_orders_arr *orders_arr);

/**
 * Função utilizada para imprimir toda a informação de uma encomenda.
 * @param order
 */
void h_order_print(t_order *order);

/**
 * A função pede o códigop ao utilizador e mostra as encomendas
 * do utilizador com aquele código.
 * @param orders_arr
 */
void h_orders_list_mine(t_orders_arr *orders_arr);

/**
 *  * A função permite ao admin listar todas as encomendas existentes.
 * @param orders_arr
 */
void h_orders_list_all(t_orders_arr *orders_arr);

/**
 * A função permite ao admin listar todas as encomendas canceladas.
 * @param orders_arr
 */
void h_orders_list_canceled(t_orders_arr *orders_arr);

#endif //PROJETOFINAL_ORDERS_H
