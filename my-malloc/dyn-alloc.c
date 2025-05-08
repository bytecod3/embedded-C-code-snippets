/**
 * Basic malloc usage
 *
 * best practises
 * always check for NULL pointer returned
 * Ensure every allocated memory is freed after use
 * use sizeof operator to make code portable
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main() {
    int* ptr  = (int*) malloc(sizeof(int));

    if (ptr == NULL) {
        puts("Memory allocation fails\n");
        return 1;

    } else {
        puts("Memory allocated OK\n");

        // allocate memory for a simple integer
        int n = 789;
        *ptr = n;

        printf("%d\n", *ptr);
    }

    // allocating for arrays
    int *arr_mem = (int*) malloc(ARRAY_SIZE * sizeof(int));
    for(int i =0; i < ARRAY_SIZE; i++) {
        arr_mem[i] = i * 5;
    }

    // display the array
    for(int i = 0; i < ARRAY_SIZE;i++) {
        printf("%d\n", arr_mem[i]);
    }

    free(arr_mem);

    // zeroeing memory on allocation using memset
    int* num_arr = (int*) malloc(10 * sizeof(int));

    if(num_arr != NULL) {
        memcpy(num_arr, 0, 10 * sizeof(int));
    }

    return 0;

}

