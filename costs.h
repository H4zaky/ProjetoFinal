#ifndef PROJETOFINAL_COSTS_H
#define PROJETOFINAL_COSTS_H

#include "articles.h"
#include "utils.h"

typedef struct {
    enum FOOTWEAR_TYPE type;
    float hand_work;
    float fixed_cost;
    float margin;
} t_global_costs;

typedef struct {
    enum FOOTWEAR_TYPE type;
    int footwear_size;
    float price;
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

int import_costs();

int read_costs(t_costs *costs, int i);

void expand_costs_array(t_costs *costs);

t_costs *h_costs_alloc();

void h_costs_free(t_costs *costs);

/**
 *
 * @param global_costs
 * @param fixed_costs
 * @return
 */
int h_costs_add(t_costs *costs);

#endif //PROJETOFINAL_COSTS_H
