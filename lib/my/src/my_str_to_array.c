/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** convert str to word array
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

static bool is_split_char(char const *str, char const c)
{
    if (c == '\0')
        return true;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return true;
    return false;
}

static int get_size(char const *str, char const *c_list, bool const keep_splits)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (i > 0 && !is_split_char(c_list, str[i - 1])
        && is_split_char(c_list, str[i]))
            count++;
    if (keep_splits)
        for (int i = 0; str[i] != '\0'; i++)
            count += is_split_char(c_list, str[i]) ? 1 : 0;
    count += is_split_char(c_list, str[my_strlen(str) - 1]) ? 1 : 2;
    return count;
}

static void do_split(char const *str, char const *c_list,
                    bool const keep_splits, char **tab)
{
    int word = 0;
    bool in_marks = str[0] == '"';

    for (int i = 1; i <= my_strlen(str); i++) {
        if (!in_marks && ((!keep_splits && !is_split_char(c_list, str[i - 1])
                    && is_split_char(c_list, str[i]))
                    || (keep_splits && (is_split_char(c_list, str[i])
                    || (i > 0 && is_split_char(c_list, str[i - 1]))
                    || i == my_strlen(str))))) {
            tab[word++] = my_strndup(str[0] == '"' ? str + 1 : str,
                                    str[i - 1] == '"' ? i - 2 : i);
            str += i;
            if (!keep_splits && str[0] != '\0')
                for (; str[0] != '\0' && is_split_char(c_list, str[0]); str++);
            i = 0;
        }
        in_marks = str[i] == '"' ? !in_marks : in_marks;
    }
    tab[word] = NULL;
}

char **my_str_to_array(char const *str, char const *c_list,
                    bool const keep_splits)
{
    char **tab;
    int count = 0;

    if (str == NULL || str[0] == '\0')
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '"')
            count++;
    if (count % 2 != 0)
        return NULL;
    for (; !keep_splits && is_split_char(c_list, str[0]); str++);
    tab = malloc(sizeof(char *) * get_size(str, c_list, keep_splits));
    if (tab == NULL)
        return NULL;
    do_split(str, c_list, keep_splits, tab);
    return tab;
}