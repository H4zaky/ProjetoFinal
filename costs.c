#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "costs.h"

int randomize_code() {
    int cost_code;
    srand(time(NULL));
    cost_code = rand() % 9999;
    return cost_code;
}

int collect_global_costs_info(t_costs *costs, int i) {
    float hand_work;
    float fixed_cost;
    float margin;

    hand_work = h_utils_read_float(0, 20, INSERT_HAND_WORK_COST"\n");
    fixed_cost = h_utils_read_float(0, 20, INSERT_FIXED_COST_COST"\n");
    margin = h_utils_read_float(0, 1, INSERT_MARGIN_COST"\n");

    costs->global_costs->global_costs_arr[i].hand_work = hand_work;
    costs->global_costs->global_costs_arr[i].fixed_cost = fixed_cost;
    costs->global_costs->global_costs_arr[i].margin = margin;

    return 1;
}

int collect_fixed_costs_info(t_costs *costs, int i) {
    int type;
    int footwear_size;
    float price;

    type = h_utils_read_int(0, 2, INSERT_TYPE_SHOE"\n");
    footwear_size = h_utils_read_int(10, 50, INSERT_FOOTWEAR_SIZE"\n");
    price = h_utils_read_float(0, 10, INSERT_PRICE_SHOE"\n");

    costs->global_costs->global_costs_arr[i].type = type;
    costs->fixed_costs->fixed_costs_arr[i].footwear_size = footwear_size;
    costs->fixed_costs->fixed_costs_arr[i].price = price;

    return 1;
}


void expand_costs_array(t_costs *costs) {
    int new_global_costs_size;
    int new_fixed_costs_size;

    new_global_costs_size = costs->global_costs->size * 2;
    new_fixed_costs_size = costs->fixed_costs->size * 2;

    costs->global_costs = realloc(costs->global_costs, new_global_costs_size * sizeof(t_costs));
    if (costs->global_costs == NULL) {
        printf("Não Alocou\n");
        exit(1);
    }

    costs->global_costs->size = new_global_costs_size;

    for (int i = costs->global_costs->count; i < costs->global_costs->size; i++) {
        costs->global_costs->global_costs_arr[i].type = 0;
        costs->global_costs->global_costs_arr[i].hand_work = 0;
        costs->global_costs->global_costs_arr[i].fixed_cost = 0;
        costs->global_costs->global_costs_arr[i].margin = 0;
    }

    costs->fixed_costs = realloc(costs->fixed_costs, new_fixed_costs_size * sizeof(t_costs));
    if (costs->fixed_costs == NULL) {
        printf("Não Alocou\n");
        exit(1);
    }

    costs->fixed_costs->size = new_fixed_costs_size;

    for (int i = costs->fixed_costs->count; i < costs->fixed_costs->size; i++) {
        costs->fixed_costs->fixed_costs_arr[i].type = 0;
        costs->fixed_costs->fixed_costs_arr[i].footwear_size = 0;
    }
}

t_costs *h_costs_alloc() {
    t_costs *costs = malloc(sizeof(t_costs));

    if (costs == NULL) {
        return NULL;
    }

    costs->global_costs = malloc(sizeof(t_global_costs_arr));

    if (costs->global_costs == NULL) {
        return NULL;
    }

    costs->fixed_costs = malloc(sizeof(t_fixed_costs_arr));

    if (costs->fixed_costs == NULL) {
        return NULL;
    }

    costs->global_costs->size = 50;
    costs->global_costs->count = 0;

    costs->global_costs->global_costs_arr = calloc(
            costs->global_costs->size,
            sizeof(t_global_costs));

    if (costs->global_costs->global_costs_arr == NULL) {
        return NULL;
    }

    costs->fixed_costs->size = 50;
    costs->fixed_costs->count = 0;

    costs->fixed_costs->fixed_costs_arr = calloc(
            costs->fixed_costs->size,
            sizeof(t_specific_costs));

    if (costs->fixed_costs->fixed_costs_arr == NULL) {
        return NULL;
    }

    return costs;
}

void h_costs_free(t_costs *costs) {
    free(costs->global_costs->global_costs_arr);
    free(costs->fixed_costs->fixed_costs_arr);

    free(costs->global_costs);
    free(costs->fixed_costs);

    free(costs);
}

int h_costs_add(t_costs *costs) {
    int cost_code;

    if (costs->global_costs->count == costs->global_costs->size &&
        costs->fixed_costs->count == costs->fixed_costs->size) {
        expand_costs_array(costs);
    }

    cost_code = randomize_code();

    costs->global_costs->global_costs_arr[costs->global_costs->count].cost_code = cost_code;
    costs->fixed_costs->fixed_costs_arr[costs->fixed_costs->count].cost_code = cost_code;

    collect_fixed_costs_info(costs, costs->fixed_costs->count++);
    collect_global_costs_info(costs, costs->global_costs->count++);

    return 1;
}

int h_costs_update(t_costs *costs, int cost_code) {
    cost_code = h_utils_read_int(0, 9999, INSERT_COSTS_CODE);

    for (int i = 0; i < costs->global_costs->count; i++) {
        if (costs->global_costs->global_costs_arr[i].cost_code == cost_code) {
            return collect_global_costs_info(costs, i);
        }
    }

    for (int j = 0; j < costs->fixed_costs->count; j++) {
        if (costs->fixed_costs->fixed_costs_arr[j].cost_code == cost_code) {
            return collect_fixed_costs_info(costs, j);
        }
    }

    return 0;
}

void h_costs_remove(t_costs *costs, int cost_code) {
    cost_code = h_utils_read_int(0, 9999, INSERT_COSTS_CODE);

    for (int i = 0; i < costs->global_costs->count; i++) {
        if (cost_code == costs->global_costs->global_costs_arr[i].cost_code) {
            costs->global_costs->global_costs_arr[i] = costs->global_costs->global_costs_arr[i + 1];
        }
    }

    for (int j = 0; j < costs->fixed_costs->count; j++) {
        if (cost_code == costs->fixed_costs->fixed_costs_arr[j].cost_code) {
            costs->fixed_costs->fixed_costs_arr[j] = costs->fixed_costs->fixed_costs_arr[j + 1];
        }
    }
}

void h_costs_list(t_costs *costs) {
    for (int i = 0; i < costs->global_costs->count; i++) {
        h_global_costs_print(&costs->global_costs->global_costs_arr[i]);
    }
    for (int j = 0; j < costs->fixed_costs->count; j++) {
        h_fixed_costs_print(&costs->fixed_costs->fixed_costs_arr[j]);
    }
}

void h_global_costs_print(t_global_costs *global_costs) {
    printf("Custos Globais:");
    printf("\n----\n");
    printf("Código do Custo: %d\n", global_costs->cost_code);
    printf("Custo de Mão de Obra: %f\n", global_costs->hand_work);
    printf("Custos Fixos: %f\n", global_costs->fixed_cost);
    printf("Margem: %f", global_costs->margin);
    printf("\n----\n");
}

void h_fixed_costs_print(t_specific_costs *specific_costs) {
    printf("Custos Fixos:");
    printf("\n----\n");
    printf("Código do Custo: %d\n", specific_costs->cost_code);
    printf("Tipo de Sapato: %d\n", specific_costs->type);
    printf("Tamanho do Sapato: %d\n", specific_costs->footwear_size);
    printf("Custo do Sapato: %f\n", specific_costs->price);
    printf("\n----\n");
}
