#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "articles.h"
#include "utils.h"

int find_article_code(t_arr_articles *articles_arr, int code);

int read_article(t_arr_articles *articles_arr, int i) {
    int code, footWearSize, laborWork, fixedCosts;
    float footWearCosts;
    // reuse memory
    char *name = articles_arr->articles[i].name;

    code = h_utils_read_int(0, 9999, CODE_INPUT_ARTICLE);
    if (find_article_code(articles_arr, code)) {
        printf(CODE_EXISTS);
        return 0;
    }

    footWearSize = h_utils_read_int(34, 48, FOOTWEAR_SIZE_INPUT);
    footWearCosts = h_utils_read_float(0.65f, 1.35f, FOOTWEAR_COSTS_INPUT);
    laborWork = h_utils_read_int(0, 10, LABOR_WORK_INPUT);
    fixedCosts = h_utils_read_int(0, 10, FIXED_COSTS_INPUT);

    h_utils_read_string(name, 64, NAME_INPUT_ARTICLE);

    articles_arr->articles[i].code = code;
    articles_arr->articles[i].name = name;
    articles_arr->articles[i].footWearSize = footWearSize;
    articles_arr->articles[i].footWearCosts = footWearCosts;
    articles_arr->articles[i].laborWork = laborWork;
    articles_arr->articles[i].fixedCosts = fixedCosts;

    return 1;
}

int find_article_code(t_arr_articles *articles_arr, int code) {
    for (int i = 0; i < articles_arr->count; i++) {
        if (articles_arr->articles[i].code == code) {
            return 1;
        }
    }
    return 0;
}

void expand_articles_array(t_arr_articles *articles_arr) {
    int new_size;

    new_size = articles_arr->size * 2;

    articles_arr->articles = (t_article *) realloc(articles_arr->articles, new_size * sizeof(t_article));
    if (articles_arr->articles == NULL) {
        printf("Não alocou!");
        exit(1);
    }

    articles_arr->size = new_size;

    for (int i = articles_arr->count; i < new_size; i++) {
        articles_arr->articles[i].name = (char *) calloc(64, sizeof(char));
        articles_arr->articles[i].code = 0;
    }
}

t_arr_articles *h_articles_alloc() {

    t_arr_articles *articles_arr = (t_arr_articles *) malloc(sizeof(t_arr_articles));
    if (articles_arr == NULL) {
        return NULL;
    }

    articles_arr->count = 0;
    articles_arr->size = 1;

    articles_arr->articles = (t_article *) calloc(articles_arr->size, sizeof(t_article));
    if (articles_arr->articles == NULL) {
        return NULL;
    }

    for (int i = 0; i < articles_arr->size; i++) {
        articles_arr->articles[i].name = (char *) calloc(64, sizeof(char));
        articles_arr->articles[i].code = 0;

    }

    return articles_arr;
}

void h_articles_free(t_arr_articles *articles_arr) {
    for (int i = 0; i < articles_arr->size; i++) {
        free(articles_arr->articles[i].name);
    }

    free(articles_arr->articles);
    free(articles_arr);
}

int h_articles_add(t_arr_articles *articles_arr) {

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

int h_articles_remove(t_arr_articles *articles_arr, int code) {
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
    articles_arr->articles[articles_arr->count - 1].fixedCosts = 0;
    articles_arr->articles[articles_arr->count - 1].footWearCosts = 0;
    articles_arr->articles[articles_arr->count - 1].laborWork = 0;
    articles_arr->articles[articles_arr->count - 1].type = 0;
    articles_arr->articles[articles_arr->count - 1].footWearSize = 0;

    articles_arr->count--;

    printf(REMOVE_INPUT);
    return 0;
}

int h_articles_update(t_arr_articles *articles_arr, int code) {
    for (int i = 0; i < articles_arr->count; ++i) {
        if (articles_arr->articles[i].code == code) {
            return read_article(articles_arr, i);
        }
    }

    return 0;
}

void h_articles_list(t_arr_articles *articles_arr) {
    for (int i = 0; i < articles_arr->count; ++i) {
        printf("\n----\n");
        printf("Código de Artigo: %d\n", articles_arr->articles[i].code);
        printf("Nome do Artigo: %s\n", articles_arr->articles[i].name);
        printf("Custo fixo: %d\n", articles_arr->articles[i].fixedCosts);
        printf("Custo de Mão de Obra: %d\n", articles_arr->articles[i].laborWork);
        printf("Preço do sapato: %0.2f\n", articles_arr->articles[i].footWearCosts);
        printf("Tamanho do Sapato: %d\n", articles_arr->articles[i].footWearSize);
        printf("Tipo de calçado: %c\n", articles_arr->articles[i].type);
        printf("\n----\n");
    }
}

