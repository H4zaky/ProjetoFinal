cmake_minimum_required(VERSION 3.10)
project(ProjetoFinal C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetoFinal main.c clients.c clients.h utils.c utils.h articles.c articles.h orders.c orders.h menus.c menus.h strs.h costs.c costs.h)
