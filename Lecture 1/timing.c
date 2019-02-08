/*  timing.c

02346, F19, DTU

See Databar Exercise 1 for instructions.

*/

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define LIMIT_I 40000
#define LIMIT_J 40000

struct timeval tv;
struct timespec tp;
struct timespec tp2;
 
double get_current_time_seconds1() {
    /* Get current time using gettimeofday */
    gettimeofday(&tv, NULL);
    //printf("%ld", tv.tv_sec);
    return (double)  tv.tv_usec;
}

double get_current_time_seconds2() { 
    /* Get current time using clock_gettime using CLOCK_REALTIME */
    //printf("%d",  CLOCK_REALTIME);
    clock_gettime(CLOCK_REALTIME, &tp);
    return (double) tp.tv_sec;
}

double get_current_time_seconds3() { 
    /* Get current time using clock_gettime using CLOCK_MONOTONIC */
    //printf("%d", CLOCK_MONOTONIC);
    clock_gettime(CLOCK_MONOTONIC, &tp2);
    return (double) tp2.tv_sec;
}

int main() {
    int i, j;
    int x = 0;
    double start1, end1; /* timing variables [seconds] */
    double start2, end2; /* timing variables [seconds] */
    double start3, end3; /* timing variables [seconds] */

    start1 = get_current_time_seconds1();
   // start2 = get_current_time_seconds2();
   // start3 = get_current_time_seconds3();

    /* Some hard work */
    for (i = 0; i < LIMIT_I; i++) {
        for (j = 0; j < LIMIT_J; j++) {
            x = x + i*j;
        }
    }

    end1 = get_current_time_seconds1();
   // end2 = get_current_time_seconds2();
    //end3 = get_current_time_seconds3();

    printf("Elapsed time: %1.6f sec\n"
           "              %1.6f sec\n"
           "              %1.6f sec\n", 
           end1-start1, end2-start2, end3-start3);
 
}

