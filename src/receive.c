/*
** EPITECH PROJECT, 2019
** navy
** File description:
** receive
*/

#include "my.h"
#include "navy.h"

static bool does_wait(bool does_toggle)
{
    static bool status = true;

    if (!does_toggle && !status) {
        status = true;
        return false;
    }
    if (does_toggle)
        status = false;
    return status;
}

void increase_status(__attribute((unused))int sig,
                    __attribute((unused))siginfo_t *siginfo,
                    __attribute((unused))void *context)
{
    does_wait(true);
}

static int get_value(bool does_increase, int *rec_pid)
{
    static int pid = 0;
    static int value = 0;
    int result = value;

    if (does_increase) {
        pid = *rec_pid;
        value++;
    } else {
        *rec_pid = pid;
        value = 0;
    }
    return result;
}

void increase_values(__attribute((unused))int sig, siginfo_t *siginfo,
                    __attribute((unused))void *context)
{
    get_value(true, &siginfo->si_pid);
}

receive_t receive_values()
{
    receive_t receive;

    while (does_wait(false));
    receive.x = get_value(false, &receive.pid);
    while (does_wait(false));
    receive.y = get_value(false, &receive.pid);
    return receive;
}