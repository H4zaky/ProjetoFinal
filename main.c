#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articles.h"
#include "clients.h"
#include "utils.h"
#include "orders.h"
#include "database.h"
#include "menus.h"

void admin_menu(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

void client_menu(t_clients_arr *clients_arr, t_orders_arr *orders_arr, t_articles_arr *articles_arr);

void profile_menu(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr);

int main() {

    h_menus_profile();

    /*
    t_clients_arr *clients_arr = NULL;
    t_articles_arr *articles_arr = NULL;
    t_orders_arr *orders_arr = NULL;

    articles_arr = h_articles_alloc();
    if (articles_arr == NULL) {
        free(articles_arr);
        perror("Articles Exit\n");
        return 1;
    }

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        free(articles_arr);
        perror("Clients Exited\n");
        return 1;
    }

    orders_arr = h_orders_alloc();
    if (orders_arr == NULL) {
        free(orders_arr);
        perror("Orders Exited\n");
        return 1;
    }

    profile_menu(clients_arr, articles_arr, orders_arr);

    h_clients_free(clients_arr);
    h_articles_free(articles_arr);
    h_orders_free(orders_arr);
    */
    return 0;
}

void profile_menu(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int profile;

    do {
        printf("Opção 1 = Admin\n");
        printf("Opção 2 = Cliente\n");
        printf("Opção 0 = Sair\n");
        profile = h_utils_read_int(0, 2, INSERT_PROFILE_INPUT);

        if (profile == 1) {
            admin_menu(clients_arr, articles_arr, orders_arr);
        } else if (profile == 2) {
            client_menu(clients_arr, orders_arr, articles_arr);
        }

    } while (profile != 0);
}

void admin_menu(t_clients_arr *clients_arr, t_articles_arr *articles_arr, t_orders_arr *orders_arr) {
    int op;

    do {
        printf("*******************************************\n");
        printf("*              Menu Principal             *\n");
        printf("*                                         *\n");
        printf("* 1.Criar                                 *\n");
        printf("* 2.Editar                                *\n");
        printf("* 3.Remover                               *\n");
        printf("* 4.Listar                                *\n");
        printf("* 5.Persistência de Dados                 *\n");
        printf("* 0.Sair                                  *\n");
        printf("*******************************************\n");

        op = h_utils_read_int(0, 5, INSERT_OPTION_INPUT);

        switch (op) {
            case 1:
                do {
                    printf("*******************************************\n");
                    printf("*               Opção Criar               *\n");
                    printf("*                                         *\n");
                    printf("* 1.Criar Cliente                         *\n");
                    printf("* 2.Criar Artigo                          *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 3, INSERT_OPTION_INPUT);

                    switch (op) {
                        case 1:
                            h_clients_add(clients_arr);
                            break;
                        case 2:
                            h_articles_add(articles_arr);
                            break;
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 2:
                do {
                    printf("*******************************************\n");
                    printf("*               Opção Remover             *\n");
                    printf("*                                         *\n");
                    printf("* 1.Remover Cliente                         *\n");
                    printf("* 2.Remover Artigo                        *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 3, INSERT_OPTION_INPUT);

                    switch (op) {
                        case 1:
                            h_clients_remove(clients_arr, h_utils_read_int(1, 9999, INSERT_CLIENT_CODE_INPUT));
                            break;
                        case 2:
                            h_articles_remove(articles_arr, h_utils_read_int(1,9999, INSERT_ARTICLE_CODE_INPUT));
                            break;
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 3:
                do {
                    printf("*******************************************\n");
                    printf("*               Opção Editar              *\n");
                    printf("*                                         *\n");
                    printf("* 1.Editar Cliente                       *\n");
                    printf("* 2.Editar Artigo                        *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 3, INSERT_OPTION_INPUT);

                    switch (op) {
                        case 1:
                            h_clients_update(clients_arr, h_utils_read_int(1, 9999, INSERT_CLIENT_CODE_INPUT));
                            break;
                        case 2:
                            h_articles_update(articles_arr, h_utils_read_int(1,9999, INSERT_ARTICLE_CODE_INPUT));
                            break;
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 4:
                do {
                    printf("*******************************************\n");
                    printf("*               Opção Listar              *\n");
                    printf("*                                         *\n");
                    printf("* 1.Listar Cliente                        *\n");
                    printf("* 2.Listar Artigo                         *\n");
                    printf("* 3.Listar Todas as Encomendas            *\n");
                    printf("* 4.Listar Todas as Encomendas Canceladas *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 4, INSERT_OPTION_INPUT);

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
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 5:
                do {
                    printf("*******************************************\n");
                    printf("*          Persistência de Dados          *\n");
                    printf("*                                         *\n");
                    printf("* 1.Guardar Cliente                       *\n");
                    printf("* 2.Carregar Cliente                      *\n");
                    printf("* 3.Guardar Artigos                       *\n");
                    printf("* 4.Carregar Artigos                      *\n");
                    printf("* 5.Guardar Encomendas                    *\n");
                    printf("* 6.Carregar Encomendas                   *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 6, INSERT_OPTION_INPUT);

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
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 0:
                printf("Exite\n");
        }
    } while (op != 0);
}

void client_menu(t_clients_arr *clients_arr, t_orders_arr *orders_arr, t_articles_arr *articles_arr) {
    int op;

    do {
        printf("*******************************************\n");
        printf("*               Menu Principal            *\n");
        printf("*                                         *\n");
        printf("* 1.Cliente                               *\n");
        printf("* 2.Encomenda                             *\n");
        printf("* 3.Artigos                               *\n");
        printf("* 0.Sair                                  *\n");
        printf("*******************************************\n");

        op = h_utils_read_int(0, 3, INSERT_OPTION_INPUT);

        switch (op) {
            case 1:
                do {
                    printf("*******************************************\n");
                    printf("*                 Cliente                 *\n");
                    printf("*                                         *\n");
                    printf("* 1.Criar Cliente                         *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 2, INSERT_OPTION_INPUT);

                    switch (op) {
                        case 1:
                            h_clients_add(clients_arr);
                            break;
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 2:
                do {
                    printf("*******************************************\n");
                    printf("*               Encomenda                 *\n");
                    printf("*                                         *\n");
                    printf("* 1.Criar Encomenda                       *\n");
                    printf("* 2.Editar Encomenda                      *\n");
                    printf("* 3.Cancelar Encomenda                    *\n");
                    printf("* 4.Listar Encomenda                      *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 4, INSERT_OPTION_INPUT);

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
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 3:
                do {
                    printf("*******************************************\n");
                    printf("*                 Artigos                 *\n");
                    printf("*                                         *\n");
                    printf("* 1.Listar Artigos Disponíveis            *\n");
                    printf("* 0.Sair                                  *\n");
                    printf("*******************************************\n");

                    op = h_utils_read_int(0, 2, INSERT_OPTION_INPUT);

                    switch (op) {
                        case 1:
                            h_articles_list(articles_arr);
                            break;
                        case 0:
                            printf("Exit\n");
                    }
                } while (op != 0);
                break;
            case 0:
                printf("Exit\n");
                break;
        }
    } while (op != 0);
}
