/*
** EPITECH PROJECT, 2019
** navy
** File description:
** defend ships
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

static int edit_map(player_t *player, int pid, int const x, int const y)
{
    my_putchar(x + 'A');
    my_putchar(y + '0' + 1);
    if (player->map_player[y][x] > 0) {
        player->map_player[y][x] = HIT_VALUE;
        my_putstr(": hit\n\n");
        if (send_values(pid, 1, 0))
            return EXIT_ERROR;
    } else {
        player->map_player[y][x] = MISS_VALUE;
        my_putstr(": missed\n\n");
        if (send_values(pid, 0, 1))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int defend(player_t *player, int pid, bool error)
{
    receive_t receive;

    if (!error) {
        if (!player->toggle)
            put_positions(player);
        my_putstr("waiting for enemy's attack...\n");
    }
    receive = receive_values();
    if (receive.pid != pid)
        return EXIT_ERROR;
    usleep(N_TRANS_SLEEP);
    if (receive.x > MAP_SIZE - 1 || receive.y > MAP_SIZE - 1) {
        my_put_error_str("Error during connection\n");
        if (send_values(pid, 3, 3) == EXIT_ERROR)
            return EXIT_ERROR;
        return defend(player, pid, true);
    }
    return edit_map(player, receive.pid, receive.x, receive.y);
}