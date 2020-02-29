/*
** EPITECH PROJECT, 2019
** navy
** File description:
** receive
*/

#include "my.h"
#include "navy.h"

static int calc_bits(bool reset, bool bit, int *sig_pid)
{
    static int pid = 0;
    static int count = 0;
    static int value = 0;
    int result = 0;

    if (count >= 6 && reset) {
        for (int i = 0; i < 6; i++, value >>= 1) {
            result <<= 1;
            result += value & 0b00000001;
        }
        count = 0;
        value = 0;
        *sig_pid = pid;
        return result;
    } else if (!reset) {
        value = (value << 1) + bit;
        count++;
        pid = *sig_pid;
    }
    return -1;
}

void sig_signal(int sig, siginfo_t *siginfo, __attribute((unused))void *context)
{
    calc_bits(false, sig == SIGUSR1, &siginfo->si_pid);
}

receive_t receive_values(void)
{
    receive_t receive;
    int value = -1;

    while (value == -1)
        value = calc_bits(true, false, &receive.pid);
    receive.x = value & 0b00000111;
    receive.y = (value & 0b00111000) >> 3;
    return receive;
}