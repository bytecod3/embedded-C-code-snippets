#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_distinct(int* arr, int len);

int main(int argc, char**argv) {
    if(argc != 2) {
        return EXIT_FAILURE; // no file provided
    }

    FILE* fptr = fopen(argv[1], "r");
    if(fptr == NULL) {
        return EXIT_FAILURE;
    }

    int length=0;
    int value;

    while( fscanf(fptr, "%d", &value) == 1){
        length++;
    }

    // test comment

    fseek (fptr, 0, SEEK_SET);
    int* arr = malloc(length * sizeof(int));
    length = 0;

    while(fscanf(fptr, "%d", &(arr[length])) == 1){
        length++;
    }

    fclose(fptr);

    int dist = are_distinct(arr, length);
    printf("The elements are ");
    if(dist == 0) {
        printf("not");
    }
    printf(" distinct");
    free(arr);
    return EXIT_SUCCESS;
}

