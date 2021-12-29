#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "strs.h"

int h_menus_builder(const char *menu_msg, const char *input_msg, int min_op, int max_op) {
    int op;

    printf("%s", menu_msg);
    op = h_utils_read_int(min_op, max_op, input_msg);

    return op;
}

void h_menus_profile(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_MENU, INSERT_PROFILE, 0, 2);

    switch (op) {
        case 1:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        case 2:
            h_menus_client(clients_arr, articles_arr, orders_arr);
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            break;
    }
}

void h_menus_admin(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_ADMIN, INSERT_OPTION, 0, 5);

    switch (op) {
        case 1:
            h_menus_admin_create(clients_arr, articles_arr, orders_arr);
            break;
        case 2:
            h_menus_admin_update(clients_arr, articles_arr, orders_arr);
            break;
        case 3:
            h_menus_admin_remove(clients_arr, articles_arr, orders_arr);
            break;
        case 4:
            h_menus_admin_list(clients_arr, articles_arr, orders_arr);
            break;
        case 5:
            h_menus_admin_database(clients_arr, articles_arr, orders_arr);
            break;
        case 0:
            h_menus_profile(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }
}

void h_menus_client(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_PROFILE_CLIENT, INSERT_OPTION, 0, 3);

    switch (op) {
        case 1:
            h_clients_add(clients_arr);
            break;
        case 2:
            h_menus_client_orders(clients_arr, articles_arr, orders_arr);
            break;
        case 3:
            h_articles_list(articles_arr);
            break;
        case 0:
            h_menus_profile(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_client(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_admin_create(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_CREATE, INSERT_OPTION, 0, 2);

    switch (op) {
        case 1:
            h_clients_add(clients_arr);
            break;
        case 2:
            h_articles_add(articles_arr);
            break;
        case 0:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_admin_create(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_admin_update(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_UPDATE, INSERT_OPTION, 0, 2);

    switch (op) {
        case 1:
            h_clients_update(clients_arr, h_utils_read_int(0, 9999, INSERT_CLIENT_CODE));
            break;
        case 2:
            h_articles_update(articles_arr, h_utils_read_int(0, 9999, INSERT_ARTICLE_CODE));
            break;
        case 0:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_admin_update(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_admin_remove(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_REMOVE, INSERT_OPTION, 0, 2);

    switch (op) {
        case 1:
            h_clients_remove(clients_arr, h_utils_read_int(0, 9999, INSERT_CLIENT_CODE));
            break;
        case 2:
            h_articles_remove(articles_arr, h_utils_read_int(0, 9999, INSERT_ARTICLE_CODE));
            break;
        case 0:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_admin_remove(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_admin_list(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_LIST, INSERT_OPTION, 0, 2);

    switch (op) {
        case 1:
            h_clients_list(clients_arr);
            break;
        case 2:
            h_articles_list(articles_arr);
            break;
        case 3:
            h_orders_list_all(orders_arr);
            break;
        case 4:
            h_orders_list_canceled(orders_arr);
            break;
        case 0:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_admin_list(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_admin_database(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_ADMIN_DATABASE, INSERT_OPTION, 0, 6);

    switch (op) {
        case 1:
            h_database_write_clients(clients_arr);
            break;
        case 2:
            h_database_read_clients();
            break;
        case 3:
            h_database_write_articles(articles_arr);
            break;
        case 4:
            h_database_read_articles();
            break;
        case 5:
            h_database_write_orders(orders_arr);
            break;
        case 6:
            h_database_read_orders();
            break;
        case 0:
            h_menus_admin(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_admin_database(clients_arr, articles_arr, orders_arr);
    }
}

void h_menus_client_orders(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    op = h_menus_builder(H_STRS_CLIENT_ORDERS, INSERT_OPTION, 0, 4);

    switch (op) {
        case 1:
            h_orders_add(orders_arr, clients_arr);
            break;
        case 2:
            h_orders_update(orders_arr);
            break;
        case 3:
            h_orders_cancel(orders_arr);
            break;
        case 4:
            h_orders_list_mine(orders_arr);
            break;
        case 0:
            h_menus_client(clients_arr, articles_arr, orders_arr);
            break;
        default:
            break;
    }

    if (op != 0) {
        h_menus_client_orders(clients_arr, articles_arr, orders_arr);
    }
}

