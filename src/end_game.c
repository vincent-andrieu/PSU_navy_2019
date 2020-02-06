/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check end of game
*/

#include <stdbool.h>
#include "navy.h"

static bool is_lose(player_t *player)
{
    for (int y = 0; player->map_player[y]; y++)
        for (int x = 0; x < MAP_SIZE; x++)
            if (player->map_player[y][x] > 0)
                return false;
    return true;
}

bool is_end_game(game_t *my_game)
{
    if (is_lose(my_game->player_one)) {
        my_putstr(MSG_LOSE);
        return false;
    }
    if (is_lose(my_game->player_two)) {
        my_putstr(MSG_WIN);
        return false;
    }
    return true;
}