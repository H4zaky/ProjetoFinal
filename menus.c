#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "strs.h"
#include "utils.h"


int h_menus_builder(const char *menu_msg, const char *input_msg, int min_op, int max_op) {
    int op;

    printf("%s", menu_msg);
    op = h_utils_read_int(min_op, max_op, input_msg);

    return op;
}

void h_menus_profile() {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_MENU, INSERT_PROFILE_INPUT, 0, 2);

    switch (op) {
        case 1:
            h_menus_admin();
            break;
        case 2:
            h_menus_client();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            break;
    }
}

void h_menus_admin(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_ADMIN, INSERT_OPTION_INPUT,0,5);

    switch (op) {
        case 1:
            h_menus_admin_create();
            break;
        case 2:
            h_menus_admin_update();
            break;
        case 3:
            h_menus_admin_remove();
            break;
        case 4:
            h_menus_admin_list();
            break;
        case 5:
            h_menus_admin_database();
            break;
        case 0:
            h_menus_profile();
            break;
        default:
            break;
    }
}

void h_menus_client(t_clients_arr *clients_arr, t_orders_arr *orders_arr, t_articles_arr *articles_arr) {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_CLIENT, INSERT_OPTION_INPUT, 0, 5);

    switch (op) {
        case 1:
            h_clients_add(clients_arr);
            break;
        case 2:
            h_menus_client_orders();
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 0:
            h_menus_profile();
            break;
        default:
            break;
      }
}

void h_menus_admin_create() {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_CREATE, INSERT_OPTION_INPUT, 0, 2);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 0:
            h_menus_admin();
            break;
        default:
            break;
    }
}

void h_menus_admin_update() {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_UPDATE, INSERT_OPTION_INPUT, 0, 2);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 0:
            h_menus_admin();
            break;
        default:
            break;
    }
}

void h_menus_admin_remove() {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_REMOVE, INSERT_OPTION_INPUT, 0, 2);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 0:
            h_menus_admin();
            break;
        default:
            break;
    }
}

void h_menus_admin_list() {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_LIST, INSERT_OPTION_INPUT, 0, 2);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 0:
            h_menus_admin();
            break;
        default:
            break;
    }
}

void h_menus_admin_database() {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_DATABASE, INSERT_OPTION_INPUT, 0, 6);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 0:
            h_menus_admin();
            break;
        default:
            break;
    }
}

void h_menus_client_orders() {
    int op;

    op = h_menus_builder(H_STRS_CLIENT_ORDERS, INSERT_OPTION_INPUT, 0, 4);

    switch (op) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 0:
            h_menus_client();
            break;
        default:
            break;
    }
}

