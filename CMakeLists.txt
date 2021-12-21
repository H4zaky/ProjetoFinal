cmake_minimum_required(VERSION 3.10)
project(ProjetoFinal C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetoFinal main.c clients.c clients.h utils.c utils.h articles.c articles.h orders_management/shopping_cart.c orders_management/shopping_cart.h orders_management/orders.c orders_management/orders.h)
