#include <stdio.h>
#include "articles.h"
#include "clients.h"
#include "utils.h"

int main() {

    int op;

    t_arr_clients *clients_arr = NULL;
    t_arr_articles *articles_arr = NULL;

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        return 1;
    }
    articles_arr = h_articles_alloc();
    if (articles_arr == NULL) {
        return 1;
    }

    do {
        printf("*******************************************\n");
        printf("*                   Menu                  *\n");
        printf("*                                         *\n");
        printf("* 1.Criar Cliente                         *\n");
        printf("* 2.Editar Cliente                        *\n");
        printf("* 3.Remover Cliente                       *\n");
        printf("* 4.Adicionar Artigo                      *\n");
        printf("* 5.Editar Artigo                         *\n");
        printf("* 6.Remover Artigo                        *\n");
        printf("* 7.Registo de Encomendas                 *\n");
        printf("* 0.Sair                                  *\n");
        printf("*******************************************\n");

        op = h_utils_read_int(0, 7, INSERT_OPTION_INPUT);

        switch (op) {
            case 1:
                h_clients_add(clients_arr);
                break;
            case 2:
                printf(INSERT_CODE_INPUT);
                h_clients_update(clients_arr, h_utils_read_int(1, 9999, VALOR_INVALIDO));
                break;
            case 3:
                printf(INSERT_CODE_INPUT);
                h_clients_remove(clients_arr, h_utils_read_int(1, 9999, VALOR_INVALIDO));
                break;
            case 4:
                h_articles_add(articles_arr);
                break;
            case 5:
                printf(INSERT_CODE_INPUT);
                h_articles_update(articles_arr, h_utils_read_int(1, 9999, VALOR_INVALIDO));
                break;
            case 6:
                printf(INSERT_CODE_INPUT);
                h_articles_remove(articles_arr, h_utils_read_int(1, 9999, VALOR_INVALIDO));
                break;
            case 0:
                printf("Exit");
                break;
            default:
                printf("ETROY");
        }
    } while (op != 0);

    h_clients_free(clients_arr);
    h_articles_free(articles_arr);

    return 0;
}
