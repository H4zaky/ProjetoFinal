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
 *Função utilizada para imprimir toda a informação de um artigo.
 * @param article
 */
void h_article_print(const t_article *article);

/**
 * Aloca memória para um array de artigos.
 * @return um array de artigos.
 */
t_articles_arr *h_articles_alloc();

/**
 * Função para libertar a memória do array de artigos.
 * @param articles_arr
 */
void h_articles_free(t_articles_arr *articles_arr);

/**
 * Adiciona um artigo ao array de artigos.
 * @return 1 se adicionado com sucesso, caso-contrário 0.
 */
int h_articles_add(t_articles_arr *articles_arr);

/**
 *Procura o artigo pelo código e remove-o.
 * @param code código do artigo.
 * @return 1 se removido com sucesso, caso-contrário 0.
 */
int h_articles_remove(t_articles_arr *articles_arr, int code);

/**
 * Procura o artigo pelo código e atualiza as informações do artigo.
 * @param code código do artigo.
 * @return 1 se atualizado com sucesso, caso-contrário 0.
 */
int h_articles_update(t_articles_arr *articles_arr, int code);

/**
 * Itera o array de artigos.
 * @param articles_arr
 */
void h_articles_list(t_articles_arr *articles_arr);

#endif //PROJETOFINAL_ARTICLES_H

