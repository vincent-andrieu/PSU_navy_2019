/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check map errors
*/

#include "my.h"
#include "navy.h"

static bool check_coords(char *str)
{
    str[1] = '\0';
    if (!my_str_isnum(str))
        return true;
    str += 2;
    if (!((str[0] == str[3]) ^ (str[1] == str[4])))
        return true;
    if (str[0] >= str[3] && str[1] >= str[4])
        return true;
    return false;
}

static bool check_nums(char *coord)
{
    char const str[3] = {coord[3], coord[6], '\0'};

    if (coord[0] < '2' || coord[0] > '5')
        return true;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '1' || str[i] > '8')
            return true;
    return false;
}

static bool check_letters(char *coord)
{
    char const str[3] = {coord[2], coord[5], '\0'};

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'H')
            return true;
    return false;
}

bool check_map_errors(char **map)
{
    int i = 0;
    bool boats_size[4] = {false, false, false, false};

    for (; map[i] != NULL; i++) {
        if (check_nums(map[i]) || check_letters(map[i]) || check_coords(map[i]))
            return true;
        if (boats_size[map[i][0] - '0' - 2])
            return true;
        else
            boats_size[map[i][0] - '0' - 2] = true;
    }
    if (i != 4)
        return true;
    return false;
}