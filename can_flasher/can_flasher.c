/**
 * @file can_flasher.c
 * @brief Main file of can source project.
 *
 * @author Slave77 <henry.slave77@gmail.com>
 */

#include <nuttx/config.h>
#include <stdio.h>
#include <time.h>

#include "can.h"



static double TimeSpecToSeconds(struct timespec* ts){
    return (double)ts -> tv_sec + (double)ts->tv_sec / 1000000000.0;
}

#ifdef CONFIG_BUILD_KERNEL
int main (int argc, FAR char *argv[])
#else
int can_flasher_main(int argc, char *argv[])
#endif
{
    struct timespec start;
    struct timespec end;
    double elapsed_secs;

    CanInit();

    int N = 10;
    int i = 1;

    printf("[%s] I am good at counting! Here I go... \n", __PRETTY_FUNCTION__);
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (i <= N) {
            printf("%d \n", i);
            i = i + 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_secs = TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start);
    printf("\n See... I counted %d numbers in %.3f seconds", N, elapsed_secs);

    return 0;
}
