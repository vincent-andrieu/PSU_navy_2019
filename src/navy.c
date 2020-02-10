/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy script
*/

#include "my.h"
#include "navy.h"

static int exit_navy(player_t *player, int exit_value)
{
    if (player == NULL)
        return exit_value;
    for (int i = 0; player->map_player && player->map_player[i] != NULL; i++)
        free(player->map_player[i]);
    free(player->map_player);
    for (int i = 0; player->map_enemy && player->map_enemy[i] != NULL; i++)
        free(player->map_enemy[i]);
    free(player->map_enemy);
    free(player);
    return exit_value;
}

static player_t *get_player_maps(int argc, char **argv)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->toggle = argc == 2;
    player->map_player = get_map(argv[argc == 3 ? 2 : 1]);
    player->map_enemy = get_int_array();
    if (player->map_player == NULL || player->map_enemy == NULL) {
        exit_navy(player, EXIT_ERROR);
        return NULL;
    }
    return player;
}

int navy(int argc, char **argv)
{
    player_t *player = get_player_maps(argc, argv);
    int enemy_pid;

    if (player == NULL)
        return exit_navy(player, EXIT_ERROR);
    enemy_pid = init_connection(argc, argv[1]);
    if (enemy_pid <= 0)
        return exit_navy(player, EXIT_ERROR);
    return exit_navy(player, game(player, enemy_pid, argc == 2));
}