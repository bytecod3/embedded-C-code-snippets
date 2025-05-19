#include <stdio.h>
#include <string.h>

int c_strlen(char* str) {
    int length = 0;
    while((*str) != '\0') {
        length++;
        str++;
    }

    return length;
}

int main() {
    char str1[] = {'h', 'e', 'l'};

    int len1;

    len1 = c_strlen(str1);

    //printf("Len: %d", len1);

    char src[] = "Hello";
    char dest[6];
    strcpy(dest, src);

    //printf("%s\n", dest);

    char* chptr;
    char s[] = "structure";
    chptr = strstr(s, "ruct");

    printf("%p", (void*) chptr);

    return 0;
}