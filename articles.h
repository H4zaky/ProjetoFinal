#ifndef PROJETOFINAL_ARTICLES_H
#define PROJETOFINAL_ARTICLES_H

enum FOOTWEAR_TYPE {
    SAPATO,
    SANDALIAS,
    BOTAS
};

typedef struct {
    int laborWork;
    int fixedCosts;
    int footWearSize;
    int footWearCosts;
    enum FOOTWEAR_TYPE type;
} t_article;

typedef struct {
    t_article *clients;
    int count; // Representa o espaço total ocupado e a posição livre
    int size; // Tamanho total do array
} t_arr_articles;

/**
 * Alloc memory for an array of articles.
 * @return the array of articles.
 */
t_arr_articles *h_articles_alloc();

void h_articles_free(t_arr_articles *articles_arr);

/**
 * Add a new article to the array.
 * @return 1 if successful added, 0 otherwise.
 */
int h_articles_add(t_arr_articles *articles_arr);

/**
 * Finds a article by its's code and */
int h_articles_remove(t_arr_articles *articles_arr);
#endif //PROJETOFINAL_ARTICLES_H
