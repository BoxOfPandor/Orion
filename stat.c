/*
** EPITECH PROJECT, 2024
** Orion
** File description:
** stat.c
*/

#include <stdio.h>
#include "include/orion.h"

stat_t get_stat_player(void)
{
    stat_t stats;
    char input[100];
    int num;

    do {
        printf("-------------------- Enter Stat --------------------\n");
        printf("Enter your stats of str, dex, con, int, cha, wis:\n");
        fgets(input, 100, stdin);
        num = sscanf(input, "%d %d %d %d %d %d", &stats.str, &stats.dex, &stats.con,
                     &stats.intell, &stats.cha, &stats.wis);
        if (num != 6) {
            printf("Error: You must enter 6 values.\n");
        }
    } while (num != 6);
    putchar('\n');
    return stats;
}

modif_t get_modif_player(void)
{
    modif_t modif;
    char input[100];
    int num;

    do {
        printf("-------------------- Enter Modif --------------------\n");
        printf("Enter your modifs of str, dex, con, int, cha, wis:\n");
        fgets(input, 100, stdin);
        num = sscanf(input, "%d %d %d %d %d %d", &modif.str, &modif.dex, &modif.con,
                     &modif.intell, &modif.cha, &modif.wis);
        if (num != 6) {
            printf("Error: You must enter 6 values.\n");
        }
    } while (num != 6);
    putchar('\n');
    return modif;
}

void print_stat(stat_t stats, modif_t modif)
{
    printf("|-------|------------ Your Stat ------------|\n");
    printf("|       | Str | Dex | Con | Int | Cha | Win |\n");
    printf("|-------|-----|-----|-----|-----|-----|-----|\n");
    printf("| Stats | %3d | %3d | %3d | %3d | %3d | %3d |\n", stats.str, stats.dex,
           stats.con, stats.intell, stats.cha, stats.wis);
    printf("|-------|-----|-----|-----|-----|-----|-----|\n");
    printf("| Modif | %+3d | %+3d | %+3d | %+3d | %+3d | %+3d |\n", modif.str, modif.dex,
           modif.con, modif.intell, modif.cha, modif.wis);
    printf("|-------|-----------------------------------|\n");
}
