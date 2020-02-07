/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy script
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
    my_putstr("\nenemy connected\n");
    return receive.pid;
}

static int send_pid(char *enemy_pid)
{
    int pid = my_getnbr(enemy_pid);

    if (!my_str_isnum(enemy_pid))
        return EXIT_ERROR;
    if (send_values(pid, CONNECT_VALS, CONNECT_VALS) != EXIT_SUCCESS)
        return EXIT_ERROR;
    my_putstr("successfully connected\n");
    return EXIT_SUCCESS;
}

static void init_signals(void)
{
    struct sigaction act;
    sigset_t sa_mask;

    my_putstr("my_pid:\t");
    my_put_nbr(getpid());
    my_putchar('\n');
    sigemptyset(&sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_mask = sa_mask;
    act.sa_sigaction = &increase_values;
    sigaction(SIGUSR1, &act, NULL);
    act.sa_sigaction = &increase_status;
    sigaction(SIGUSR2, &act, NULL);
}

int navy(int argc, char **argv)
{
    int **map = get_map(argv[argc == 3 ? 2 : 1]);
    int enemy_pid;
    int exit_value = EXIT_SUCCESS;

    if (map == NULL)
        return EXIT_ERROR;
    init_signals();
    if (argc == 2)
        enemy_pid = get_enemy_pid();
    else if (argc == 3)
        exit_value = send_pid(argv[1]);
    if (enemy_pid <= 0)
        return EXIT_ERROR;
    for (int i = 0; map[i] != NULL; free(map[i]), i++);
    free(map);
    return exit_value;
}