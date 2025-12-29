/* WAP to Implement Singly Linked List with following
operations
a) Createalinkedlist.
b) Insertion of a node at first position, at any position and
at end of list.
Display the contents of the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_first(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = head;
    head = t;
}

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

void insert_pos(int x, int pos)
{
    if (pos == 1)
    {
        insert_first(x);
        return;
    }
    struct node *p = head;
    for (int i = 1; i < pos - 1 && p; i++)
        p = p->next;
    if (p)
    {
        struct node *t = malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
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
    insert_first(5);
    insert_pos(15, 3);
    display();
    return 0;
}

/* Output:
5 10 15 20
*/
