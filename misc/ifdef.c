#include <stdio.h>
#include <assert.h>
//#define SAY_HI

#define BOARD1 0
#define BOARD2  1

int main(){

#ifdef MESSAGE
    puts(MESSAGE);
#endif

    return 0;
}