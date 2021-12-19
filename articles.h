#ifndef PROJETOFINAL_ARTICLES_H
#define PROJETOFINAL_ARTICLES_H

#define CODE_INPUT_ARTICLE "Código do Artigo:"
#define NAME_INPUT_ARTICLE "Nome do Artigo:"
#define FOOTWEAR_SIZE_INPUT "Tamanho do sapato (34~48):"
#define FOOTWEAR_COSTS_INPUT "Preço do sapato (0.65~1.35):"
#define LABOR_WORK_INPUT "Custo da mão de obra (0~10):"
#define FIXED_COSTS_INPUT "Custo fixo do sapato (0~10):"
#define REMOVE_INPUT "O artigo foi removido!"

#define CODE_EXISTS "O número inserido para o código já existe!"

enum FOOTWEAR_TYPE {
    SAPATO,
    SANDALIAS,
    BOTAS
};

typedef struct {
    int code;
    char *name;
    int laborWork;
    int fixedCosts;
    int footWearSize;
    float footWearCosts;
    enum FOOTWEAR_TYPE type;
} t_article;

typedef struct {
    t_article *articles;
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
 * Finds a article by its's code and remove it.
 * @param code the code of the article.
 * @return 1 if found and remove, 0 otherwise.
 */
int h_articles_remove(t_arr_articles *articles_arr, int code);

/**
 * Finds and updates articles data.
 * @param code the code of the article.
 * @return 1 if found and successful updated, 0 otherwise.
 */
int h_articles_update(t_arr_articles *articles_arr, int code);

void h_articles_list(t_arr_articles *articles_arr);

#endif //PROJETOFINAL_ARTICLES_H

