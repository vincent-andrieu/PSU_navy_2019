/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy script
*/

#include "my.h"
#include "navy.h"

static int exit_navy(int **map, int exit_value)
{
    for (int i = 0; map[i] != NULL; free(map[i]), i++);
    free(map);
    return exit_value;
}

int navy(int argc, char **argv)
{
    int **map = get_map(argv[argc == 3 ? 2 : 1]);
    int enemy_pid;

    if (map == NULL)
        return EXIT_ERROR;
    enemy_pid = init_connection(argc, argv[1]);
    if (enemy_pid <= 0)
        return exit_navy(map, EXIT_ERROR);
    return exit_navy(map, EXIT_SUCCESS);
}