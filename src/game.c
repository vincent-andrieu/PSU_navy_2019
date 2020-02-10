/*
** EPITECH PROJECT, 2019
** navy
** File description:
** manage game
*/

#include <my.h>
#include "navy.h"

static int is_finish(player_t *player)
{
    int n = 0;

    for (int i = 0; player->map_enemy[i] != NULL; i++)
        for (int k = 0; k < MAP_SIZE; k++)
             n += player->map_enemy[i][k] == HIT_VALUE;
    if (n >= MAX_HITS_NBR) {
        my_putstr(MSG_WIN);
        return EXIT_WIN;
    }
    n = 0;
    for (int i = 0; player->map_player[i] != NULL; i++)
        for (int k = 0; k < MAP_SIZE; k++)
             n += player->map_player[i][k] == HIT_VALUE;
    if (n >= MAX_HITS_NBR) {
        my_putstr(MSG_LOSE);
        return EXIT_LOSE;
    }
    return -1;
}

void put_positions(player_t *player)
{
    my_putstr("my positions:\n");
    my_display_map(player->map_player);
    my_putstr("enemy's positions:\n");
    my_display_map(player->map_enemy);
}

int game(player_t *player, int pid, bool is_player)
{
    int exit_value;

    if (is_player) {
        if (attack(player, pid) != EXIT_SUCCESS)
            return EXIT_ERROR;
    } else
        if (defend(player, pid) != EXIT_SUCCESS)
            return EXIT_ERROR;
    exit_value = is_finish(player);
    if (exit_value == EXIT_WIN)
        return EXIT_WIN;
    if (exit_value == EXIT_LOSE)
        return EXIT_LOSE;
    return game(player, pid, !is_player);
}