#include <stdlib.h>
#include <assert.h>

#include "counter.h"

// this struct is only visible in this file - making it opaque
struct counter{
    int value;
};

// implement counter functions
struct counter* createCounter(void){
    struct counter* c;
    c = malloc(sizeof(struct counter));
    assert(c);

    // initialize value to 0
    c->value = 0;

    return c;

}

void destroyCounter(struct counter* c){
    free(c);
}

int incrementCounter(struct counter* c){
    return ++(c->value);
}