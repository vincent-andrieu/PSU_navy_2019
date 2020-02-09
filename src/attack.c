/*
** EPITECH PROJECT, 2019
** navy
** File description:
** attack ships
*/

#include <unistd.h>
#include "my.h"
#include "navy.h"

static char *ask_attack(void)
{
    char *pos = malloc(sizeof(char) * 4);
    int size;

    if (pos == NULL)
        return NULL;
    my_putstr("attack: ");
    size = read(0, pos, 4);
    if (size != 3 || pos[2] != '\n')
        return NULL;
    pos[2] = '\0';
    return pos;
}

static int is_touched(int pid, char *attack, int **map_enemy)
{
    receive_t receive = receive_values();

    my_putstr(attack);
    if (receive.pid != pid)
        return EXIT_ERROR;
    if (receive.x == 1 && receive.y == 0) {
        map_enemy[attack[0] - 'A'][attack[1] - '0' - 1] = HIT_VALUE;
        my_putstr(": hit\n");
    } else if (receive.x == 0 && receive.y == 1) {
        map_enemy[attack[0] - 'A'][attack[1] - '0' - 1] = MISS_VALUE;
        my_putstr(": missed\n");
    } else
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int attack(player_t *player, int pid)
{
    char *attack;

    put_positions(player);
    do {
        attack = ask_attack();
        if (attack == NULL)
            return EXIT_ERROR;
    } while (attack[0] < 'A' || attack[0] > 'A' + MAP_SIZE - 1
    || attack[1] < '1' || attack[1] > '1' + MAP_SIZE - 1);
    if (send_values(pid, attack[0] - 'A' + 1, attack[1] - '0') != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (is_touched(pid, attack, player->map_enemy) != EXIT_SUCCESS)
        return EXIT_ERROR;
    free(attack);
    return EXIT_SUCCESS;
}