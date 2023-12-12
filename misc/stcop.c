#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcpy2(char* dest, const char* src){
    while(*dest++ = *src++);
}

char* strcpy2a(char* dest, const char* src){
    int i = 0;

    for(i=0; src[i] != '\0'; i++){
        dest[i] = src[i];

    }

    //final null in src is not copied by the loop
    dest[i] = '\0';
    return dest;
}

char* copySubstring(char* dest, const char* src, int start, int end){
    // copy the substring
    strncpy(dest, src+start, end-start);

    // add null since strncpy didnt
    dest[end - start] = '\0';

    return dest;

}

int strcmp2(const char* s1, const char* s2){
    while(*s1 && *s2 && *s1 == *s2){
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

char* copyEven(char* dest, const char* src){
    int i =0, j = 0, len;
    len = strlen(src);

    for(i=0, j=0; i < len; i += 2, j++){
        dest[j] = src[i];
    }

    // add null character
    dest[j] = '\0';

    return dest;
}

// create memory location for a copy of a string
char* strdup2(const char* s){
    char* s2;

    s2 = malloc(strlen(s) + 1);

    if(s2 != 0){
        strcpy(s2, s);
    }

    return s2;
}

int main(){
    char* d;
    const char* s1 = "edwin";
    const char* s2 = "eduh";

    int c;

    //copySubstring(d, s, 5, 10);
    //copyEven(d, s);

    c = strcmp2(s1, s2);

    //puts(d);

    printf("result: %d", c);

    return 0;

}