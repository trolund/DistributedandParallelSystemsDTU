//
// Created by Troels on 2019-02-07.
//

#include <stdio.h>


int main(){

    const char * word = "Hi There";

    int[5] * array_pointer;
    int  array[5];
    array_pointer  = &array;

    //printf(*array); // print addres for array that the pointer holes.

    for (int i = 0; i < sizeof(array)-1; ++i) {
        *array_pointer = i+1;
       // printf("%p", &array_pointer); // addresen
        printf("%d", *array_pointer);
        array_pointer++;
    }

    return 0;
}
