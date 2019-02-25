/*  restest.c

02346, F19, DTU

See Mandatory Assignement 1, Problem 6 for instructions.

*/

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#define SAMPLES 100
#define LOAD      1

long sample[SAMPLES];
int main() {
  long register start;
  int register i,j, k;
  long register dummy;

  struct timespec timeSpec1, timeSpec2;

 for (i = 0; i < SAMPLES; i++) {
    k = i*LOAD;
    dummy = 0;
    clock_gettime(CLOCK_MONOTONIC,&timeSpec1);
 
    /* Workload */
    for (j = 0; j < k; j++) {
      dummy++;
    }

    clock_gettime(CLOCK_MONOTONIC,&timeSpec2);
    start     = timeSpec1.tv_sec*1e9 + timeSpec1.tv_nsec;
    sample[i] = timeSpec2.tv_sec*1e9 + timeSpec2.tv_nsec - start;

 }

  for (i = 1; i < SAMPLES; i++) {
      printf("%4d %6li\n", i, sample[i]);
  }

}
