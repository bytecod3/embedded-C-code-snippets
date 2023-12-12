#include <stdio.h>

struct string{
    int length;
    char* data;
};

int main(int argc, char** argv){
    struct string s;
    struct string* sp;
    sp = &s; // pointer to s

    s.length = 4;
    s.data = "this is longer than u think";

    puts(sp->data);

    s.data = "another long string";
    puts((*sp).data);


    return 0;
}