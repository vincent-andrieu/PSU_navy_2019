/*
** EPITECH PROJECT, 2019
** navy
** File description:
** edit map
*/

#include "my.h"
#include "navy.h"

void edit_map(player_t *player, int pid, int const x, int const y)
{
    my_putchar(x + 'A' - 1);
    my_putchar(y + '0');
    if (player->map_player[y - 1][x - 1] > 0) {
        player->map_player[y - 1][x - 1] = HIT_VALUE;
        my_putstr(": hit\n");
        send_values(pid, 1, 0);
    } else {
        player->map_player[y - 1][x - 1] = MISS_VALUE;
        my_putstr(": missed\n");
        send_values(pid, 0, 1);
    }
}