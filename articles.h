#ifndef PROJETOFINAL_ARTICLES_H
#define PROJETOFINAL_ARTICLES_H

#define CODE_INPUT_ARTICLE "Código do Artigo:"

#define INSERT_ARTICLE_CODE_INPUT "Insira o código do artigo:"
#define INSERT_ARTICLE_NAME_INPUT "Insira um nome para o artigo:"
#define INSERT_ARTICLE_MAX_SIZE_INPUT "Insira o tamanho máximo:"
#define INSERT_ARTICLE_MIN_SIZE_INPUT "Insira o tamanho mínimo:"
#define INSERT_ARTICLE_TYPE_INPUT "Tipo de Sapato:"

#define REMOVE_ARTICLE_INPUT "O artigo foi removido!"

#define CODE_EXISTS "O número inserido para o código já existe!"

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
} t_arr_articles;

/**
 *
 * @param article
 */
void h_article_print(const t_article *article);

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
 * Finds a article by it's code and remove it.
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

