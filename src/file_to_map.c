/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "navy.h"

static int **get_int_array(void)
{
    int **my_map = malloc(sizeof(int *) * (MAP_SIZE + 1));

    if (!my_map)
        return NULL;
    my_map[MAP_SIZE] = NULL;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        my_map[i] = malloc(sizeof(int) * MAP_SIZE);
        if (!my_map[i])
            return NULL;
        for (int u = 0; u < MAP_SIZE; u++)
            my_map[i][u] = SEA_VALUE;
    }
    return my_map;
}

static int array_filler(int **my_map, char *line)
{
    int boat_size;
    char **tab = my_str_to_array(line, ":", false);

    if (!tab)
        return 84;
    boat_size = my_getnbr(tab[0]);
    if (tab[1][0] == tab[2][0])
        for (int i = my_getnbr(tab[1] + 1) - 1; i < my_getnbr(tab[2] + 1); i++)
            my_map[i][tab[1][0] - 65] = boat_size;
    else
        for (int i = tab[1][0] - 65; i <= tab[2][0] - 65; i++)
            my_map[my_getnbr(tab[1] + 1) - 1][i] = boat_size;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return 0;
}

int **get_int_array_from_map(char **map)
{
    int ret;
    int **my_map = get_int_array();

    if (!my_map)
        return NULL;
    for (int i = 0; map[i]; i++) {
        ret = array_filler(my_map, map[i]);
        if (ret == 84)
            return NULL;
    }
    return my_map;
}

void my_display_map(int **my_map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int y = 0; my_map[y]; y++) {
        my_put_nbr(y + 1);
        my_putchar('|');
        for (int x = 0; x < MAP_SIZE; x++) {
            if (my_map[y][x] == -1)
                my_putstr("o");
            if (my_map[y][x] == -2)
                my_putstr("x");
            if (my_map[y][x] == SEA_VALUE)
                my_putstr(".");
            if (my_map[y][x] != -1 && my_map[y][x] != -2 && my_map[y][x] != 0)
                my_put_nbr(my_map[y][x]);
            if (x + 1 < MAP_SIZE)
                my_putchar(' ');
        }
        my_putchar('\n');
    }
}

int main(void)
{
    char *map[] = { "2:C1:C2",
                    "3:D4:F4",
                    "4:B5:B8",
                    "5:D7:H7",
                    NULL};
    int **my_map = get_int_array_from_map(map);
    my_display_map(my_map);

    
    for (int y = 0; my_map[y]; y++)
        free(my_map[y]);
    free(my_map);
    return 0;
}