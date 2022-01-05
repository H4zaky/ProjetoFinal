#ifndef PROJETOFINAL_COSTS_H
#define PROJETOFINAL_COSTS_H

#include "articles.h"

typedef struct {
    enum FOOTWEAR_TYPE type;
    float hand_work;
    float fixed_cost;
    float margin;
} t_global_costs;

typedef struct {
    enum FOOTWEAR_TYPE type;
    int size;
    float price;
} t_specific_costs;

typedef struct {
    int counter;
    int size;
    t_global_costs *global_costs;
} t_arr_global_costs;

typedef struct {
    int counter;
    int size;
    t_specific_costs *fixed_costs;
} t_arr_fixed_costs;

typedef struct {
    t_arr_global_costs global_costs;
    t_arr_fixed_costs fixed_costs;
} t_costs;
int import_costs();

#endif //PROJETOFINAL_COSTS_H
