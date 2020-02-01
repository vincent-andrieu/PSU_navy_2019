/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare 2 strings in the alphabet
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 84;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == s2[i] && s1[i + 1] == '\0' && s2[i + 1] != '\0')
            return -1;
        if (s1[i] == s2[i] && s2[i + 1] == '\0' && s1[i + 1] != '\0')
            return 1;
    }
    return 0;
}
