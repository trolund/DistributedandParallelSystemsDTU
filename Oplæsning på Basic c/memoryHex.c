//
// Created by Troels on 2019-02-08.
//
#include <stdio.h>

int main(int argc, char* args[]){

    int array[5];
    int* array_ptr = array;

    for (int i = 0; i < 5; ++i) {
        array[i] = i;
        printf("val: %x add: %x \n",array[i], &array[i]);
    }

    int a = 12;
    int b = 18;

    int c = (b<<1);
    printf("%d \n", b);
    printf("%d \n", a & 13);
    printf("%d \n", (b<<1 & a));

    // næmt eksemple på &:
    int x = 6; // 0110
    int y = 2; // 0100

    /* bitwise and (&)
     * 0110 = 6
     * 0100 = 2
     * ----
     * 0100 = 2
     */
    int z = x & y;
    printf("%d \n", z);


    // næmt eksemple på binært ventre skift.  <<(antal rækker rykket) :

/*
 * 0110 = 6
 *
 * Efter 6>>1
 * 1100 = 3
 *
 * Efter 3>>1
 * 1000 = 1
 *
 * kan selvfølgelig også gøres den anden vej
 *
 */

    printf("%d \n", x>>1);
    printf("%d \n", x>>2);

    printf("%d \n", 12>>1);
}