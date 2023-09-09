#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_t *createNode(int data)
{
    Node_t *temp = (Node_t *) malloc(1 * sizeof(Node_t));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void pushHead(Node_t **head, int data)
{
    Node_t *temp = createNode(data);
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}


bool pushAt(Node_t *head, int data, int pos)
{
    Node_t *pt = head;
    int i = 0;
    while (pt != NULL && i != pos-1 )
    {
        pt = pt->next;
        i++;
    }
    if (i != pos-1)
        return 0;
    else {
        Node_t *new_node = createNode(data);
        new_node->next = pt->next;
        pt->next = new_node;
    }

    return 1;
}


void pushTail(Node_t *head, int data)
{
    Node_t *pt = head;
    while (pt->next != NULL )
    {
        pt = pt->next;
    }
    Node_t *new_node = createNode(data);
    pt->next = new_node;
}


bool delAt(Node_t *head, int pos)
{
    Node_t *pt = head;
    int i = 0;
    while (pt != NULL && i != pos )
    {
        pt = pt->next;
        i++;
    }

    if (i != pos)
        return 0;
    else {
        Node_t *temp = pt->next;
        pt = head;
        i--;
        while (i--)
        {
            pt = pt->next;
        }
        pt->next = temp;
    }

    return 1;
}


void delHead(Node_t **head)
{
    Node_t *pt = *head;
    pt = pt->next;
    *head = pt;
}








void delTail(Node_t *head)
{
    Node_t *pt = head;
    int i=0;
    while (pt->next != NULL)
    {
        pt = pt->next;
        i++;
    }
    i--;
    pt = head;
    while (i--)
    {
        pt = pt->next;
    }
    pt->next = NULL;
}
