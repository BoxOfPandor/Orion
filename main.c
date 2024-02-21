/*
** PERSO PROJECT, 2024
** Project Orion
** File description:
** main.c
*/

#include "include/orion.h"

int main(int ac, char **av)
{
    stat_t stats;
    modif_t modif;

    stats = get_stat_player();
    modif = get_modif_player();
    print_stat(stats, modif);
    return 0;
}
