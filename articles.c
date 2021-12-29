#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "articles.h"

int find_article_code(t_articles_arr *articles_arr, int code);

int read_article(t_articles_arr *articles_arr, int i) {
    int code;
    int type;
    int max_size;
    int min_size;

    //reuse memory
    char *name = articles_arr->articles[i].name;

    code = h_utils_read_int(0, 9999, CODE_INPUT_ARTICLE);
    if (find_article_code(articles_arr, code)) {
        printf(CODE_EXISTS);
        return 0;
    }

    h_utils_read_string(name, 64, INSERT_ARTICLE_NAME);
    max_size = h_utils_read_int(11, 99, INSERT_ARTICLE_MAX_SIZE);
    min_size = h_utils_read_int(11, 99, INSERT_ARTICLE_MIN_SIZE);
    type = h_utils_read_int(0, 2, INSERT_ARTICLE_TYPE);

    articles_arr->articles[i].code = code;
    articles_arr->articles[i].name = name;
    articles_arr->articles[i].type = type;
    articles_arr->articles[i].max_size = max_size;
    articles_arr->articles[i].min_size = min_size;

    return 1;
}

int find_article_code(t_articles_arr *articles_arr, int code) {
    for (int i = 0; i < articles_arr->count; i++) {
        if (articles_arr->articles[i].code == code) {
            return 1;
        }
    }
    return 0;
}

void expand_articles_array(t_articles_arr *articles_arr) {
    int new_size;

    new_size = articles_arr->size * 2;

    articles_arr->articles = (t_article *) realloc(articles_arr->articles, new_size * sizeof(t_article));
    if (articles_arr->articles == NULL) {
        perror("Not allocated");
        exit(EXIT_FAILURE);
    }

    articles_arr->size = new_size;

    for (int i = articles_arr->count; i < new_size; i++) {
        articles_arr->articles[i].name = (char *) calloc(64, sizeof(char));
        articles_arr->articles[i].code = 0;
        articles_arr->articles[i].type = 0;
        articles_arr->articles[i].max_size = 0;
        articles_arr->articles[i].min_size = 0;
    }
}

t_articles_arr *h_articles_alloc() {

    t_articles_arr *articles_arr = (t_articles_arr *) malloc(sizeof(t_articles_arr));
    if (articles_arr == NULL) {
        return NULL;
    }

    articles_arr->count = 0;
    articles_arr->size = 20;

    articles_arr->articles = (t_article *) calloc(articles_arr->size, sizeof(t_article));
    if (articles_arr->articles == NULL) {
        return NULL;
    }

    for (int i = 0; i < articles_arr->size; i++) {
        articles_arr->articles[i].name = (char *) calloc(64, sizeof(char));
        articles_arr->articles[i].code = 0;
        articles_arr->articles[i].type = 0;
        articles_arr->articles[i].max_size = 0;
        articles_arr->articles[i].min_size = 0;
    }

    return articles_arr;
}

void h_articles_free(t_articles_arr *articles_arr) {
    for (int i = 0; i < articles_arr->size; i++) {
        free(articles_arr->articles[i].name);
    }

    free(articles_arr->articles);
    free(articles_arr);
}

int h_articles_add(t_articles_arr *articles_arr) {

    if (articles_arr == NULL) {
        return 0;
    }

    if (articles_arr->count == articles_arr->size) {
        expand_articles_array(articles_arr);
    }

    if (read_article(articles_arr, articles_arr->count) != 1) {
        return 0;
    }

    articles_arr->count++;

    return 1;
}

int h_articles_remove(t_articles_arr *articles_arr, int code) {
    int position = -1;
    for (int i = 0; i < articles_arr->count; i++) {
        if (articles_arr->articles[i].code == code) {
            position = i;
        }
    }

    if (position == -1) {
        return 1;
    }

    for (int i = position; i < articles_arr->count; i++) {
        articles_arr->articles[i] = articles_arr->articles[i + 1];
    }

    free(articles_arr->articles[articles_arr->count - 1].name);
    articles_arr->articles[articles_arr->count - 1].name = (char *) calloc(64, sizeof(char));
    articles_arr->articles[articles_arr->count - 1].code = 0;
    articles_arr->articles[articles_arr->count - 1].type = 0;
    articles_arr->articles[articles_arr->count - 1].max_size = 0;
    articles_arr->articles[articles_arr->count - 1].min_size = 0;

    articles_arr->count--;

    printf(ARTICLE_REMOVED_OUTPUT"\n");
    return 0;
}

int h_articles_update(t_articles_arr *articles_arr, int code) {
    for (int i = 0; i < articles_arr->count; i++) {
        if (articles_arr->articles[i].code == code) {
            return read_article(articles_arr, i);
        }
    }

    return 0;
}

void h_articles_list(t_articles_arr *articles_arr) {
    for (int i = 0; i < articles_arr->count; i++) {
        h_article_print(&articles_arr->articles[i]);
    }
}

void h_article_print(const t_article *article) {
    printf("\n----\n");
    printf("Código de Artigo: %d\n", article->code);
    printf("Nome do Artigo: %s\n", article->name);
    printf("Tipo de calçado: %d\n", article->type);
    printf("Tamanho mínimo do sapato %d\n", article->min_size);
    printf("Tmanho máximo do sapato: %d\n", article->max_size);
    printf("\n----\n");
}

