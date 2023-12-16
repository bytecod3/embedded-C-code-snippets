#include <stdio.h>

#define Warning(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char** argv){
    Warning("%s: this program contains no useful code\n", argv[0]);

    return 1;
}