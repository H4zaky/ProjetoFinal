#ifndef PROJETOFINAL_ARTICLES_H
#define PROJETOFINAL_ARTICLES_H

#include "utils.h"

enum FOOTWEAR_TYPE {
    SAPATO = 0,
    SANDALIAS = 1,
    BOTAS = 2
};

typedef struct {
    int code;
    char *name;
    int max_size;
    int min_size;
    enum FOOTWEAR_TYPE type;
} t_article;

typedef struct {
    t_article *articles;
    int count; // Representa o espaço total ocupado e a posição livre
    int size; // Tamanho total do array
} t_articles_arr;

/**
 *
 * @param article
 */
void h_article_print(const t_article *article);

/**
 * Alloc memory for an array of articles.
 * @return the array of articles.
 */
t_articles_arr *h_articles_alloc();

void h_articles_free(t_articles_arr *articles_arr);

/**
 * Add a new article to the array.
 * @return 1 if successful added, 0 otherwise.
 */
int h_articles_add(t_articles_arr *articles_arr);

/**
 * Finds a article by it's code and remove it.
 * @param code the code of the article.
 * @return 1 if found and remove, 0 otherwise.
 */
int h_articles_remove(t_articles_arr *articles_arr, int code);

/**
 * Finds and updates articles data.
 * @param code the code of the article.
 * @return 1 if found and successful updated, 0 otherwise.
 */
int h_articles_update(t_articles_arr *articles_arr, int code);

void h_articles_list(t_articles_arr *articles_arr);

#endif //PROJETOFINAL_ARTICLES_H

