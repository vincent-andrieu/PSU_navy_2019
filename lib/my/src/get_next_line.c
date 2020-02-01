/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get the file next line
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "my.h"

static char *read_file(int fd, char **too_much, int *size);

static char *check_line(int fd, char *buffer, char **too_much, int *size)
{
    int i = my_strlen(*too_much);

    for (; buffer[i] != '\n' && buffer[i] != '\0'
    && i + 1 < READ_SIZE + my_strlen(*too_much); i++);
    if (buffer[i] == '\n') {
        free(*too_much);
        buffer[i] = '\0';
        *too_much = my_strdup(buffer + i + 1);
    } else if (buffer[i] != '\0') {
        buffer[i + 1] = '\0';
        free(*too_much);
        *too_much = buffer;
        return read_file(fd, too_much, size);
    } else {
        free(*too_much);
        *too_much = NULL;
    }
    return buffer;
}

static char *read_file(int fd, char **too_much, int *size)
{
    int much_len = my_strlen(*too_much);
    char *buffer = malloc(sizeof(char) * (much_len + READ_SIZE + 1));
    *size = buffer != NULL ? read(fd, buffer + much_len, READ_SIZE) : -1;

    if (buffer == NULL)
        return NULL;
    if (*size <= 0) {
        free(buffer);
        buffer = NULL;
        if (*too_much != NULL)
            buffer = my_strdup(*too_much);
        free(*too_much);
        *too_much = NULL;
        return buffer;
    }
    (buffer + much_len)[*size] = '\0';
    for (int k = 0; *too_much != NULL && (*too_much)[k] != '\0'; k++)
        buffer[k] = (*too_much)[k];
    return check_line(fd, buffer, too_much, size);
}

static void fill_too_much(char **result, char **too_much, char *temp)
{
    int i = 0;

    if ((*too_much) != NULL && (*too_much)[0] == '\0')
        *too_much = NULL;
    for (; (*too_much) != NULL
    && (*too_much)[i] != '\n' && (*too_much)[i] != '\0'; i++);
    if ((*too_much) != NULL && (*too_much)[i] == '\n') {
        *result = my_strndup((*too_much), i);
        (*too_much) = my_strdup((*too_much) + i + 1);
        free(temp);
    }
}

char *get_next_line(int fd)
{
    static char *too_much = NULL;
    static bool end_of_file = false;
    int size;
    char *result = NULL;
    char *temp = too_much;

    fill_too_much(&result, &too_much, temp);
    if (end_of_file) {
        end_of_file = false;
        return NULL;
    }
    temp = read_file(fd, &too_much, &size);
    end_of_file = size != READ_SIZE;
    if (end_of_file) {
        free(too_much);
        too_much = NULL;
    }
    return temp;
}