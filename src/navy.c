/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy script
*/

#include "navy.h"

int navy(int argc, char **argv)
{
    int **map = get_map(argv[argc == 3 ? 2 : 1]);

    if (map == NULL)
        return EXIT_ERROR;
    for (int i = 0; map[i] != NULL; free(map[i]), i++);
    free(map);
    return EXIT_SUCCESS;
}