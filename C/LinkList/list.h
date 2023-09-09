#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
typedef struct {
    int data;
    struct Node_t *next;
} Node_t;

Node_t *createNode(int);

bool pushAt(Node_t*, int, int);


#endif // LIST_H_INCLUDED
