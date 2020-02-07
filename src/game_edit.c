/*
** EPITECH PROJECT, 2019
** navy
** File description:
** edit map
*/

#include "my.h"
#include "navy.h"

int edit_map(player_t *player, const char *input)
{
    if (my_strlen(input) != 2)
        return EXIT_ERROR;
    if (input[0] < 65 || input[0] > 90 || input[1] < 48 || input[1] > 57)
        return EXIT_ERROR;
    my_putstr("attack: ");
    my_putstr(input);
    my_putchar('\n');
    if (player->map_player[input[1] - 48 - 1][input[0] - 65] > 0) {
        player->map_player[input[1] - 48 - 1][input[0] - 65] = HIT_VALUE;
        my_putstr(input);
        my_putstr(": hit\n");
    }
    else {
        player->map_player[input[1] - 48 - 1][input[0] - 65] = MISS_VALUE;
        my_putstr(input);
        my_putstr(": missed\n");
    }
    return 0;
}