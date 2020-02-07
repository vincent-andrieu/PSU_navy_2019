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
    for (int i = 0; i < x; i++, usleep(N_TRANS_SLEEP))
        if (kill(pid, SIGUSR1))
            return EXIT_ERROR;
    if (kill(pid, SIGUSR2))
        return EXIT_ERROR;
    usleep(N_TRANS_SLEEP);
    for (int i = 0; i < y; i++, usleep(N_TRANS_SLEEP))
        if (kill(pid, SIGUSR1))
            return EXIT_ERROR;
    if (kill(pid, SIGUSR2))
        return EXIT_ERROR;
    usleep(N_TRANS_SLEEP);
    return EXIT_SUCCESS;
}