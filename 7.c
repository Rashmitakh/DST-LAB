/* WAP to Implement doubly link list with primitive
operations
a) Create a doubly linked list.
b) Insert a new node to the left of the node.
c) Delete the node based on a specific value
d) Display the contents of the list */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_end(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->prev = t->next = NULL;
    if (head == NULL)
        head = t;
    else
    {
        struct node *p = head;
        while (p->next)
            p = p->next;
        p->next = t;
        t->prev = p;
    }
}

void insert_left(int key, int x)
{
    struct node *p = head;
    while (p && p->data != key)
        p = p->next;
    if (p)
    {
        struct node *t = malloc(sizeof(struct node));
        t->data = x;
        t->prev = p->prev;
        t->next = p;
        if (p->prev)
            p->prev->next = t;
        else
            head = t;
        p->prev = t;
    }
}

void delete_val(int x)
{
    struct node *p = head;
    while (p && p->data != x)
        p = p->next;
    if (p)
    {
        if (p->prev)
            p->prev->next = p->next;
        else
            head = p->next;
        if (p->next)
            p->next->prev = p->prev;
        free(p);
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
    insert_left(20, 15);
    delete_val(30);
    display();
    return 0;
}

/* Output:
10 15 20
*/
