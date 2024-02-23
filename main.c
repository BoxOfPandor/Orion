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
    save_throw_t save_throw;

    stats = get_stat_player();
    modif = get_modif_player();
    save_throw = get_save_throw();
    gameloop(stats, modif, save_throw);
    return 0;
}
