#include <stdio.h>
#include "articles.h"
#include "clients.h"

int main() {

    t_arr_clients *clients_arr = NULL;

    clients_arr = h_clients_alloc();
    if (clients_arr == NULL) {
        return 1;
    }

    t_arr_articles *articles_arr = NULL;

    articles_arr = h_articles_alloc();
    if (articles_arr == NULL) {
        return 1;
    }

    h_articles_add(articles_arr);

    h_articles_remove(articles_arr, 123);

    return 0;
}
