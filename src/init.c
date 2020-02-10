/*
** EPITECH PROJECT, 2019
** navy
** File description:
** initialize connection
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

static int get_enemy_pid(void)
{
    receive_t receive;

    my_putstr("waiting for enemy connection...\n");
    receive = receive_values();
    if (receive.x != CONNECT_VALS || receive.y != CONNECT_VALS)
        return -1;
    my_putstr("\nenemy connected\n\n");
    return receive.pid;
}

static int send_pid(char *enemy_pid)
{
    int pid = my_getnbr(enemy_pid);

    if (!my_str_isnum(enemy_pid))
        return -1;
    if (send_values(pid, CONNECT_VALS, CONNECT_VALS) != EXIT_SUCCESS)
        return -1;
    my_putstr("successfully connected\n\n");
    return pid;
}

static int init_signals(void)
{
    struct sigaction act;
    sigset_t sa_mask;

    my_putstr("my_pid:\t");
    my_put_nbr(getpid());
    my_putchar('\n');
    if (sigemptyset(&sa_mask) == -1)
        return EXIT_ERROR;
    act.sa_flags = SA_SIGINFO;
    act.sa_mask = sa_mask;
    act.sa_sigaction = &increase_values;
    if (sigaction(SIGUSR1, &act, NULL) == -1)
        return EXIT_ERROR;
    act.sa_sigaction = &increase_status;
    if (sigaction(SIGUSR2, &act, NULL) == -1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int init_connection(int argc, char *str_pid)
{
    int enemy_pid = -1;

    if (init_signals() != EXIT_SUCCESS)
        return -1;
    if (argc == 2)
        enemy_pid = get_enemy_pid();
    else if (argc == 3)
        enemy_pid = send_pid(str_pid);
    if (enemy_pid <= 0)
        return -1;
    return enemy_pid;
}