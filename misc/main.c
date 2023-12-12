#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NAME_LENGTH (2)
#define INITIAL_LINE_LENGTH (2)

// return a freshly malloc'd line with next line of input from stdin
char* getLine(){
    char* line;
    int size; // how much space do i have in line
    int length; // how many characters have i used

    size = INITIAL_LINE_LENGTH;
    line = malloc(size);
    assert(line);

    length = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(length >= size-1){
            // i need more space
            size *= 2;

            // make length equal to new size
            // copy contents if necessary
            line = realloc(line, size);

        }

        line[length++] = c;

    }

    line[length] = '\0';
    return line;
}

int main(){

    int x = 12;
    char* line;
    int y = 17;

    puts("What is your name: ");

    line = getLine();
    printf("Hi %s! hello THERE!", line);

    free(line);

    return 0;

}