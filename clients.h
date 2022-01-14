/**
 * @file clients.h
 * @author Carlos Leite, Pedro Teixeira, Eunice Abreu
 * @date 20/12/2021
 * @brief Clients
 */

#ifndef PROJETOFINAL_CLIENTS_H
#define PROJETOFINAL_CLIENTS_H

#include "utils.h"

typedef struct {
    int code;
    char *name;
    int nif;
    char *country;
    int removed;
} t_client;

typedef struct {
    t_client *clients;
    int count; // Representa o espaço total ocupado e a posição livre
    int size; // Tamanho total do array
} t_clients_arr;

/**
 * Aloca memória para o array de clientes.
 * @return um array de clientes.
 */
t_clients_arr *h_clients_alloc();

/**
 * Função utilizada usa o código inserido pelo utilizador para encontrar
 * um cliente e verifica se ele existe dentro do array dos cliente.
 * @param clients_arr
 * @param code
 * @return 1 se encontrado com sucesso, caso-contrário 0.
 */
int h_clients_find_by_code(t_clients_arr *clients_arr, int code);

/**
 * Função utilizada para imprimir toda a informação de um cliente.
 * @param client
 */
void h_client_print(const t_client *client);

/**
 * Função para libertar a memória do array de clientes.
 * @param clients_arr
 */
void h_clients_free(t_clients_arr *clients_arr);

/**
 * Adiciona um novo cliente ao array.
 * @return 1 se adicionado com sucesso, caso-contrário 0.
 */
int h_clients_add(t_clients_arr *clients_arr);

/**
 * Procura o cliente pelo seu código e marca-o como removido.
 * @param code código do cliente.
 * @return 1 se encontrado e marcado como removido, caso-contrário 0.
 */
void h_clients_remove(t_clients_arr *clients_arr, int code);

/**
 * Procura o cliente pelo seu código e atualiza-o.
 * @param code código do cliente.
 * @return 1 se encontrado e atualizado, caso-contrário 0.
 */
void h_clients_update(t_clients_arr *clients_arr, int code);

/**
 * Lista todos os clientes que estão marcados como removidos.
 * @param clients_arr
 */
void h_clients_list_canceled(t_clients_arr *clients_arr);
/**
 * Itera o array de clientes.
 * @param clients_arr
 */
void h_clients_list(t_clients_arr *clients_arr);

#endif //PROJETOFINAL_CLIENTS_H
