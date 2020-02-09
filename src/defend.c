/*
** EPITECH PROJECT, 2019
** navy
** File description:
** defend ships
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

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