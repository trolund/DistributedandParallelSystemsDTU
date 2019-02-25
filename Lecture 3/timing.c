#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define LIMIT_I 10000
#define LIMIT_J 100


double get_current_time_seconds1() {
    /* Get current time using gettimeofday */
    struct timeval container;
    gettimeofday(&container, NULL);
    return (double) container.tv_usec/1000000.+container.tv_sec;
}

double get_current_time_seconds2() {
    /* Get current time using clock_gettime using CLOCK_REALTIME */
    struct timespec container;
    clock_gettime(CLOCK_REALTIME, &container);
    return (double) container.tv_nsec/1000000000.+container.tv_sec;
}

double get_current_time_seconds3() {
    /* Get current time using clock_gettime using CLOCK_MONOTONIC */
    struct timespec container;
    clock_gettime(CLOCK_MONOTONIC, &container);
    return (double) container.tv_nsec/1000000000.+container.tv_sec;
}

int main() {
    int i, j, n;
    int x = 0;
    double start1, end1; /* timing variables [seconds] */
    double start2, end2; /* timing variables [seconds] */
    double start3, end3; /* timing variables [seconds] */

    for(n=100; n<250; n=n+2){
        start1 = get_current_time_seconds1();
        start2 = get_current_time_seconds2();
        start3 = get_current_time_seconds3();

        /* Some hard work */
        for (i = 0; i < n; i++) {
            for (j=0; j < LIMIT_J; j++){
                x = x + i*j;
            }
        }

        end1 = get_current_time_seconds1();
        end2 = get_current_time_seconds2();
        end3 = get_current_time_seconds3();

        printf("%d \t %1.10f \t %1.10f \t %1.10f \n",
               n*LIMIT_J, end1-start1, end2-start2, end3-start3);
    }

}
