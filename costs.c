#include <stdio.h>
#include <json.h>
#include "costs.h"

int read_costs(t_costs *costs, int i) {
    float hand_work;
    float fixed_cost;
    int type;
    float margin;
    int footwear_size;
    float price;

    type = h_utils_read_int(0, 2, INSERT_TYPE_SHOE"\n");
    hand_work = h_utils_read_float(1, 20, INSERT_HAND_WORK_COST"\n");
    fixed_cost = h_utils_read_float(1, 20, INSERT_FIXED_COST_COST"\n");
    margin = h_utils_read_float(1, 20, INSERT_MARGIN_COST"\n");
    footwear_size = h_utils_read_int(10, 50, INSERT_FOOTWEAR_SIZE"\n");
    price = h_utils_read_float(0, 10, INSERT_PRICE_SHOE"\n");

    costs->global_costs->global_costs_arr[i].type = type;
    costs->global_costs->global_costs_arr[i].hand_work = hand_work;
    costs->global_costs->global_costs_arr[i].fixed_cost = fixed_cost;
    costs->global_costs->global_costs_arr[i].margin = margin;
    costs->fixed_costs->fixed_costs_arr[i].type = type;
    costs->fixed_costs->fixed_costs_arr[i].footwear_size = footwear_size;


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
    if (costs == NULL) {
        return 0;
    }


    return 0;
}
