/*
** EPITECH PROJECT, 2019
** navy
** File description:
** send values
*/

#include <unistd.h>
#include "navy.h"

int send_values(int pid, int x, int y)
{
    int value = (y << 3) + x;

    for (int i = 0; i < 6; i++, value >>= 1, usleep(N_TRANS_SLEEP))
        if (kill(pid, value & 0b00000001 ? SIGUSR1 : SIGUSR2))
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}