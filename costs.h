/**
 * @file costs.h
 * @author Carlos Leite, Pedro Teixeira, Eunice Abreu
 * @date 07/01/2022
 * @brief Costs
 */

#ifndef PROJETOFINAL_COSTS_H
#define PROJETOFINAL_COSTS_H

#include "articles.h"
#include "utils.h"

typedef struct {
    enum FOOTWEAR_TYPE type;
    float hand_work;
    float fixed_cost;
    float margin;
    int cost_code;
} t_global_costs;

typedef struct {
    enum FOOTWEAR_TYPE type;
    int footwear_size;
    float price;
    int cost_code;
} t_specific_costs;

typedef struct {
    int count;
    int size;
    t_global_costs *global_costs_arr;
} t_global_costs_arr;

typedef struct {
    int count;
    int size;
    t_specific_costs *fixed_costs_arr;
} t_fixed_costs_arr;

typedef struct {
    t_global_costs_arr *global_costs;
    t_fixed_costs_arr *fixed_costs;
} t_costs;

/**
 * Calcula o custo do sapato com os valores inseridos pelo utilziador.
 * @param shoe_type
 * @param shoe_size
 * @param costs
 * @return o custo do sapato.
 */
float h_calculate_shoe_cost(int shoe_type, int shoe_size, t_costs *costs);

/**
 * Obtém toda a informação que diz respeito aos custos globais.
 * @param costs
 * @param i
 * @return custos globais.
 */
int collect_global_costs_info(t_costs *costs, int i);

/**
 * Obtém toda a informação que diz respeito aos custos fixos.
 * @param costs
 * @param i
 * @return custos fixos.
 */
int collect_fixed_costs_info(t_costs *costs, int i);

/**
 * Dobra o tamanho do size caso o count seja igual ao size.
 * @param costs
 */
void expand_costs_array(t_costs *costs);

/**
 * Aloca a memória no array de custos.
 * @return
 */
t_costs *h_costs_alloc();

/**
 * Liberta a memória do array de custos.
 * @param costs
 */
void h_costs_free(t_costs *costs);

/**
 * Adiciona um custo ao array de custos utlizando a funcção collect_global_costs_info e
 * collect_fixed_costs_info para obter a informação desse custo.
 * @param global_costs
 * @param fixed_costs
 * @return
 */
int h_costs_add(t_costs *costs);

/**
 * Utilza o código do custo para depois atualizá-lo.
 * @param costs
 * @param cost_code
 * @return o custo atualizado.
 */
int h_costs_update(t_costs *costs, int cost_code);

/**
 * Remove o custo do array de custos.
 * @param costs
 * @param cost_code
 */
void h_costs_remove(t_costs *costs, int cost_code);

/**
 * Lista os custos.
 * @param costs
 */
void h_costs_list(t_costs *costs);

/**
 * Faz print sobre a informação dos custos globais.
 * @param global_costs
 */
void h_global_costs_print(t_global_costs *global_costs);

/**
 * Faz print sobre a informação dos custos fixos.
 * @param specific_costs
 */
void h_fixed_costs_print(t_specific_costs *specific_costs);

#endif //PROJETOFINAL_COSTS_H
