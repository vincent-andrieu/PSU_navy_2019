/*
** EPITECH PROJECT, 2019
** navy
** File description:
** header
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef NAVY_H_
#define NAVY_H_

#define EXIT_ERROR 84
#define FILE_SIZE 31
#define NBR_BOATS 4
#define MAP_SIZE 8

#define HIT "x"
#define MISS "o"
#define SEA "."
#define SEA_VALUE 0

#define MSG_LOSE "Enemy won"
#define MSG_LOSE "I won"

typedef struct player_s
{
    int **map_player;
    int **map_ennemy;
} player_t;

typedef struct game_s
{
    player_t *player_one;
    player_t *player_two;
} game_t;

int navy(int argc, char **argv);
char **get_player_map(char *filepath);
bool check_map_errors(char **map, char *buffer);

#endif