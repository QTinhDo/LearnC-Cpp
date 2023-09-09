#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void printfAll(Node_t *head)
{
    Node_t *pt = head;
    while (pt)
    {
        printf("Data: %d\n",pt->data);
        pt = pt->next;
    }
}


int main()
{
    Node_t *head = (Node_t *)malloc(1 * sizeof(Node_t));
    Node_t *second = (Node_t *)malloc(1 * sizeof(Node_t));
    Node_t *third = (Node_t *)malloc(1 * sizeof(Node_t));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    pushHead(&head, 4);
    pushAt(head, 5, 1);
    pushTail(head, 7);
    printfAll(head);
    //delHead(&head);
    //printf("\n");
    //printfAll(head);
    delAt(head,3);
    printf("\n");
    printfAll(head);
    //delTail(head);
    //printf("\n");
    //printfAll(head);
    return 0;
}
