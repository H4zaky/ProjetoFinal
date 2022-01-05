#include <stdio.h>
#include <json.h>
#include "costs.h"

int import_costs() {
    json_object *root;

    root = json_object_from_file("/mnt/c/Users/Carlo/CLionProjects/LP/ProjetoFinal/tabeladecustos.json");
    if (!root) {
        return 1;
    }

    json_object *global_costs = json_object_object_get(root, "custos_globais");
    json_object *specific_costs = json_object_object_get(root, "custos_específicos");

    json_object *sapatos_global_costs = json_object_object_get(global_costs, "sapatos");
    json_object *sapatos_mao_obra = json_object_object_get(sapatos_global_costs, "mao_obra");

    printf("Sapatos Mão Obra: %d\n", json_object_get_int(sapatos_mao_obra));

    return 0;
}
