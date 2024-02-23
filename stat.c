/*
** EPITECH PROJECT, 2024
** Orion
** File description:
** stat.c
*/

#include <stdio.h>
#include "include/orion.h"
#include <stdbool.h>

static bool are_stats_valid(stat_t stats)
{
    if (stats.str < 0 || stats.str > 20) return false;
    if (stats.dex < 0 || stats.dex > 20) return false;
    if (stats.con < 0 || stats.con > 20) return false;
    if (stats.intell < 0 || stats.intell > 20) return false;
    if (stats.cha < 0 || stats.cha > 20) return false;
    if (stats.wis < 0 || stats.wis > 20) return false;

    return true;
}

static bool are_modifs_valid(modif_t modif)
{
    if (modif.str < -20 || modif.str > 20) return false;
    if (modif.dex < -20 || modif.dex > 20) return false;
    if (modif.con < -20 || modif.con > 20) return false;
    if (modif.intell < -20 || modif.intell > 20) return false;
    if (modif.cha < -20 || modif.cha > 20) return false;
    if (modif.wis < -20 || modif.wis > 20) return false;

    return true;
}

static bool are_save_throw_valid(save_throw_t save_throw)
{
    if (save_throw.str < -20 || save_throw.str > 20) return false;
    if (save_throw.dex < -20 || save_throw.dex > 20) return false;
    if (save_throw.con < -20 || save_throw.con > 20) return false;
    if (save_throw.intell < -20 || save_throw.intell > 20) return false;
    if (save_throw.cha < -20 || save_throw.cha > 20) return false;
    if (save_throw.wis < -20 || save_throw.wis > 20) return false;

    return true;
}

stat_t get_stat_player(void)
{
    stat_t stats;
    char input[100];
    int num;

    do {
        printf("-------------------- Enter Stat --------------------\n");
        printf("Enter your stats of str, dex, con, int, cha, wis:\n");
        fgets(input, 100, stdin);
        num = sscanf(input, "%d %d %d %d %d %d", &stats.str, &stats.dex,
                     &stats.con, &stats.intell, &stats.cha, &stats.wis);
        if (num != 6 || !are_stats_valid(stats)) {
            printf("Error: You must enter 6 values between 0 and 20.\n");
            num = 0;
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
        num = sscanf(input, "%d %d %d %d %d %d", &modif.str, &modif.dex,
                     &modif.con, &modif.intell, &modif.cha, &modif.wis);
        if (num != 6 || !are_modifs_valid(modif)) {
            printf("Error: You must enter 6 values between -20 and 20.\n");
            num = 0;
        }
    } while (num != 6);
    putchar('\n');
    return modif;
}

save_throw_t get_save_throw(void)
{
    save_throw_t save_throw;
    char input[100];
    int num;

    do {
        printf("-------------------- Enter Save Throw --------------------\n");
        printf("Enter your save throw of str, dex, con, int, cha, wis:\n");
        fgets(input, 100, stdin);
        num = sscanf(input, "%d %d %d %d %d %d", &save_throw.str, &save_throw.dex,
                     &save_throw.con, &save_throw.intell, &save_throw.cha, &save_throw.wis);
        if (num != 6 || !are_save_throw_valid(save_throw)) {
            printf("Error: You must enter 6 values between -20 and 20.\n");
            num = 0;
        }
    } while (num != 6);
    putchar('\n');
    return save_throw;
}

void print_stat(stat_t stats, modif_t modif, save_throw_t save_throw)
{
    printf("                 Your Stats                 \n");
    printf("|-------|-----------------------------------|\n");
    printf("|       | Str | Dex | Con | Int | Cha | Win |\n");
    printf("|-------|-----|-----|-----|-----|-----|-----|\n");
    printf("| Stats | %3d | %3d | %3d | %3d | %3d | %3d |\n", stats.str, stats.dex,
           stats.con, stats.intell, stats.cha, stats.wis);
    printf("|-------|-----|-----|-----|-----|-----|-----|\n");
    printf("| Modif | %+3d | %+3d | %+3d | %+3d | %+3d | %+3d |\n", modif.str, modif.dex,
           modif.con, modif.intell, modif.cha, modif.wis);
    printf("|-------|-----|-----|-----|-----|-----|-----|\n");
    printf("| Save  | %+3d | %+3d | %+3d | %+3d | %+3d | %+3d |\n", save_throw.str, save_throw.dex,
           save_throw.con, save_throw.intell, save_throw.cha, save_throw.wis);
    printf("|-------|-----------------------------------|\n");
}
