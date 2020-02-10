/*
** EPITECH PROJECT, 2019
** navy
** File description:
** defend ships
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

static void edit_map(player_t *player, int pid, int const x, int const y)
{
    my_putchar(x + 'A' - 1);
    my_putchar(y + '0');
    if (player->map_player[y - 1][x - 1] > 0) {
        player->map_player[y - 1][x - 1] = HIT_VALUE;
        my_putstr(": hit\n\n");
        send_values(pid, 1, 0);
    } else {
        player->map_player[y - 1][x - 1] = MISS_VALUE;
        my_putstr(": missed\n\n");
        send_values(pid, 0, 1);
    }
}

int defend(player_t *player, int pid)
{
    receive_t receive;

    put_positions(player);
    my_putstr("waiting for enemy's attack...\n");
    receive = receive_values();
    if (receive.pid != pid)
        return EXIT_ERROR;
    usleep(N_TRANS_SLEEP);
    edit_map(player, receive.pid, receive.x, receive.y);
    return EXIT_SUCCESS;
}