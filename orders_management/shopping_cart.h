#ifndef PROJETOFINAL_SHOPPING_CART_H
#define PROJETOFINAL_SHOPPING_CART_H

typedef struct {
    int quantity; // The requested quantity
    float base_price; // The base price of the article
    float accumulated_price; // The sum of the quantity * base price
    int article_code; // The code of the article
} t_product; // The list of products in the cart

typedef struct {
    t_product *product_list; // The list of products
    int products_list_size; // The size of the products list
    int products_list_count; // The number of products in the products list
    float total_price; // The sum of all accumulated prices
} t_shopping_cart;

int h_shopping_cart_add_article(int article_code);

int h_shopping_cart_remove_article(int article_code);

int h_shopping_cart_update_article_quantity(int article_code, int article_quantity);

void h_shopping_cart_list();

float h_shopping_cart_checkout();

/**
 * Extra functionalities (Admin)
 */
void h_shopping_cart_list_abandoned();


#endif //PROJETOFINAL_SHOPPING_CART_H
