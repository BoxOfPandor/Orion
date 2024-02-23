/*
** EPITECH PROJECT, 2024
** Orion
** File description:
** orion.h
*/


#ifndef ORION_ORION_H
    #define ORION_ORION_H
typedef struct stat_s
{
    int str;
    int dex;
    int con;
    int intell;
    int cha;
    int wis;
} stat_t;
typedef struct modif_s
{
    int str;
    int dex;
    int con;
    int intell;
    int cha;
    int wis;
} modif_t;
typedef struct save_trhow_s
{
    int str;
    int dex;
    int con;
    int intell;
    int cha;
    int wis;
} save_throw_t;
modif_t get_modif_player(void);
stat_t get_stat_player(void);
save_throw_t get_save_throw(void);
void gameloop(stat_t stat, modif_t modif, save_throw_t save_throw);
void print_stat(stat_t stats, modif_t modif, save_throw_t save_throw);
void while_roll(stat_t stat, modif_t modif);

#endif //ORION_ORION_H
