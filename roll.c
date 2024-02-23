/*
** EPITECH PROJECT, 2024
** Orion
** File description:
** roll.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/orion.h"

int rool_dice(int nb)
{
    return (rand() % nb + 1);
}

int apply_modifier(int nb, modif_t modif)
{
    int mod = 0;

    switch (nb) {
        case 1:
            mod = modif.str;
            break;
        case 2:
            mod = modif.dex;
            break;
        case 3:
            mod = modif.con;
            break;
        case 4:
            mod = modif.intell;
            break;
        case 5:
            mod = modif.cha;
            break;
        case 6:
            mod = modif.wis;
            break;
    }
    return mod;
}

int apply_mod_save(int nb, save_throw_t save_throw)
{
    int mod = 0;

    switch (nb) {
        case 1:
            mod = save_throw.str;
            break;
        case 2:
            mod = save_throw.dex;
            break;
        case 3:
            mod = save_throw.con;
            break;
        case 4:
            mod = save_throw.intell;
            break;
        case 5:
            mod = save_throw.cha;
            break;
        case 6:
            mod = save_throw.wis;
            break;
    }

    return mod;
}

void affichage(stat_t stats, modif_t modif, save_throw_t save_throw)
{
    print_stat(stats, modif, save_throw);
    printf("\n|--------------------|--------------------|\n");
    printf("|       Lancée       |        Save        |\n");
    printf("|--------------------|--------------------|\n");
    printf("|1) Strength      %+3d| 1) Strength     %+3d|\n", modif.str, save_throw.str);
    printf("|2) Dexterity     %+3d| 2) Dexterity    %+3d|\n", modif.dex, save_throw.dex);
    printf("|3) Constitution  %+3d| 3) Constitution %+3d|\n", modif.con, save_throw.con);
    printf("|4) Intelligence  %+3d| 4) Intelligence %+3d|\n", modif.intell, save_throw.intell);
    printf("|5) Charisma      %+3d| 5) Charisma     %+3d|\n", modif.cha, save_throw.cha);
    printf("|6) Wisdom        %+3d| 6) Wisdom       %+3d|\n", modif.wis, save_throw.wis);
    printf("|7) Quit             | 8) Clear           |\n");
    printf("|--------------------|--------------------|\n");
}

void roll_save_throw(stat_t stat, modif_t modif, save_throw_t save_throw)
{
    int nb;
    int i = 0;
    int rool;
    int mod;

    affichage(stat, modif, save_throw);
    while (i != 1) {
        printf("> ");
        scanf("%d", &nb);
        if (nb == 7) {
            system("clear");
            break;
        }
        else if (nb == 8) {
            system("clear");
        }
        else if (nb > 8 || nb < 0)
            printf("Entré invalide\n");
        else {
            rool = rool_dice(20);
            mod = apply_mod_save(nb, save_throw);
            printf("Vous avez fait un : %d\n\n", rool);
            printf("Votre score final avec le modificateu de %d : %d\n\n", mod, rool + mod);
            if (rool == 20)
                printf("Succes Critique !!\n\n");
            else if (rool == 1)
                printf("Echec Critique !!\n\n");
        }
    }
}

void roll_stat(stat_t stat, modif_t modif, save_throw_t save_throw)
{
    int nb;
    int i = 0;
    int rool;
    int mod;

    affichage(stat, modif, save_throw);
    while (i != 1) {
        printf("> ");
        scanf("%d", &nb);
        if (nb == 7) {
            system("clear");
            break;
        }
        else if (nb == 8) {
            system("clear");
            affichage(stat, modif, save_throw);
        }
        else if (nb > 8 || nb < 0)
            printf("Entré invalide\n");
        else {
            rool = rool_dice(20);
            mod = apply_modifier(nb, modif);
            printf("Vous avez fait un : %d\n", rool);
            printf("Votre score final avec le modificateu de %d : %d\n\n", mod, rool + mod);
            if (rool == 20)
                printf("Succes Critique !!\n\n");
            else if (rool == 1)
                printf("Echec Critique !!\n\n");
        }
    }
}

void gameloop(stat_t stat, modif_t modif, save_throw_t save_throw)
{
    int nb;
    int i = 0;

    while (i != 1) {
        printf("1) Roll Stat\n");
        printf("2) Roll Save Throw\n");
        printf("3) Quit\n");
        printf("> ");
        scanf("%d", &nb);
        if (nb == 3)
            break;
        else if (nb == 1) {
            system("clear");
            roll_stat(stat, modif, save_throw);
        }
        else if (nb == 2) {
            system("clear");
            roll_save_throw(stat, modif, save_throw);
        }
        else
            printf("Entré invalide\n");
    }
}