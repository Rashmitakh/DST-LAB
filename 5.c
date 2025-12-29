/* WAP to Implement Singly Linked List with following
operations
a) Create a linked list.
b) Deletion of first element, specified element and last
element in the list.
c) Display the contents of the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_end(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (head == NULL)
        head = t;
    else
    {
        struct node *p = head;
        while (p->next)
            p = p->next;
        p->next = t;
    }
}

void delete_first()
{
    if (head)
    {
        struct node *t = head;
        head = head->next;
        free(t);
    }
}

void delete_last()
{
    if (head == NULL) return;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct node *p = head;
    while (p->next->next)
        p = p->next;
    free(p->next);
    p->next = NULL;
}

void delete_value(int x)
{
    if (head == NULL) return;
    if (head->data == x)
    {
        delete_first();
        return;
    }
    struct node *p = head;
    while (p->next && p->next->data != x)
        p = p->next;
    if (p->next)
    {
        struct node *t = p->next;
        p->next = t->next;
        free(t);
    }
}

void display()
{
    struct node *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);
    delete_first();
    delete_value(20);
    delete_last();
    display();
    return 0;
}

/* Output:
(empty list)
*/
