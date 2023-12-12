// define function prototypes
#ifndef COUNTER_H
#define COUNTER_H

// create a new counter, initialized to 0
struct counter* createCounter(void);

// free space used by the counter
void destroyCounter(struct counter*);

// increment a counter and return the new value
int incrementCounter(struct counter*);

#endif