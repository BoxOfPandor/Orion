/*
** EPITECH PROJECT, 2024
** Orion
** File description:
** stat.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/orion.h"

stat_t get_stat_player(void)
{
    stat_t stats;

    printf("------------------------ Enter Stat ------------------------\n");
    printf("Enter your stat of strength: ");
    scanf("%d", &stats.str);
    printf("Enter your stat of dexterity: ");
    scanf("%d", &stats.dex);
    printf("Enter your stat of constitution: ");
    scanf("%d", &stats.con);
    printf("Enter your stat of intelligence: ");
    scanf("%d", &stats.intell);
    printf("Enter your stat of charisma: ");
    scanf("%d", &stats.cha);
    printf("Enter your stat of wisdom: ");
    scanf("%d", &stats.wis);
    return stats;
}

modif_t get_modif_player(void)
{
    modif_t modif;
    char input[10];

    printf("------------------------ Enter Modif ------------------------\n");
    printf("Enter your modif of strength: ");
    scanf("%s", input);
    modif.str = atoi(input);
    printf("Enter your modif of dexterity: ");
    scanf("%s", input);
    modif.dex = atoi(input);
    printf("Enter your modif of constitution: ");
    scanf("%s", input);
    modif.con = atoi(input);
    printf("Enter your modif of intelligence: ");
    scanf("%s", input);
    modif.intell = atoi(input);
    printf("Enter your modif of charisma: ");
    scanf("%s", input);
    modif.cha = atoi(input);
    printf("Enter your modif of wisdom: ");
    scanf("%s", input);
    modif.wis = atoi(input);
    return modif;
}

void print_stat(stat_t stats, modif_t modif)
{
    printf("------|------------ Your Stat ------------|\n");
    printf("      | Str | Dex | Con | Int | Cha | Win |\n");
    printf("------|-----------------------------------|\n");
    printf("Stat  | %3d | %3d | %3d | %3d | %3d | %3d |\n", stats.str, stats.dex,
           stats.con, stats.intell, stats.cha, stats.wis);
    printf("------|-----------------------------------|\n");
    printf("Modif | %+3d | %+3d | %+3d | %+3d | %+3d | %+3d |\n", modif.str, modif.dex,
           modif.con, modif.intell, modif.cha, modif.wis);
    printf("------|-----------------------------------|\n");
}
