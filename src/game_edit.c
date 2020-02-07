/*
** EPITECH PROJECT, 2019
** navy
** File description:
** edit map
*/

#include "my.h"
#include "navy.h"

int edit_map(player_t *player, const int x, const int y)
{
    my_putstr("attack: ");
    my_putchar(x + 'A');
    my_putchar(y + '0');
    my_putchar('\n');
    if (player->map_player[y - 1][x - 1] > 0) {
        player->map_player[y - 1][x - 1] = HIT_VALUE;
        my_putchar(x + 'A');
        my_putchar(y + '0');
        my_putstr(": hit\n");
    }
    else {
        player->map_player[y - 1][x - 1] = MISS_VALUE;
        my_putchar(x + 'A');
        my_putchar(y + '0');
        my_putstr(": missed\n");
    }
    return 0;
}