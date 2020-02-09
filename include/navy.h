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
#define MAX_HITS_NBR 14
#define MAP_SIZE 8
#define N_TRANS_SLEEP 5 * 1000
#define CONNECT_VALS 10

#define HIT "x"
#define MISS "o"
#define SEA "."
#define SEA_VALUE 0
#define MISS_VALUE -1
#define HIT_VALUE -2

#define MSG_WIN "I won\n"
#define MSG_LOSE "Enemy won\n"
#define EXIT_WIN 0
#define EXIT_LOSE 1

typedef struct player_s
{
    int **map_player;
    int **map_enemy;
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
int **get_int_array(void);

int init_connection(int argc, char *str_pid);
int send_values(int pid, int x, int y);
receive_t receive_values();
void increase_status(__attribute((unused))int sig,
                    __attribute((unused))siginfo_t *siginfo,
                    __attribute((unused))void *context);
void increase_values(__attribute((unused))int sig, siginfo_t *siginfo,
                    __attribute((unused))void *context);

int game(player_t *player, int pid, bool is_player);
void my_display_map(int **my_map);
void put_positions(player_t *player);
void edit_map(player_t *player, int pid, int const x, int const y);
int attack(player_t *player, int pid);
int defend(player_t *player, int pid);

#endif