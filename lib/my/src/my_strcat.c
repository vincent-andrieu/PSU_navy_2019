/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** write a string following another string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int n;

    if (dest == NULL || src == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++) {
        n = my_strlen(dest);
        dest[n] = src[i];
        dest[n + 1] = '\0';
    }
    return dest;
}
