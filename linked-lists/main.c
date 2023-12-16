#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct slinklist{
    int data;
    struct slinklist* next;
};

typedef struct slinklist node;

// create a new node
node* getNode(){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));

    // get data from the user
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    // set the next pointer to NULL
    newnode->next = NULL;

    return newnode;
}

int main(){
    // creates the start pointer
    node* start = NULL;

    // create a new node
    start = getNode();

    printf("\nAddress: %p", start);
    printf("\ndata: %d", start->data);

    return 0;
}