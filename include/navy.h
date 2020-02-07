/*
** EPITECH PROJECT, 2019
** navy
** File description:
** header
*/

#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

#ifndef NAVY_H_
#define NAVY_H_

#define EXIT_ERROR 84
#define FILE_SIZE 31
#define NBR_BOATS 4
#define MAP_SIZE 8
#define N_TRANS_SLEEP 5 * 1000
#define CONNECT_VALS 10

#define HIT "x"
#define MISS "o"
#define SEA "."
#define SEA_VALUE 0
#define MISS_VALUE -1
#define HIT_VALUE -2

#define MSG_LOSE "Enemy won"
#define MSG_WIN "I won"

typedef struct player_s
{
    int **map_player;
    int **map_ennemy;
} player_t;

typedef struct receive_s
{
    int pid;
    int x;
    int y;
} receive_t;

int navy(int argc, char **argv);
int **get_map(char *filepath);
bool check_map_errors(char **map);

int send_values(int pid, int x, int y);
receive_t receive_values();
void increase_status(__attribute((unused))int sig,
                    __attribute((unused))siginfo_t *siginfo,
                    __attribute((unused))void *context);
void increase_values(__attribute((unused))int sig, siginfo_t *siginfo,
                    __attribute((unused))void *context);

#endif