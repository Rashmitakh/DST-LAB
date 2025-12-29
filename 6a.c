/* a) WAP to Implement Single Link List with following
operations: Sort the linked list, Reverse the linked list,
Concatenation of two linked lists. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

void insert_end(struct node **head, int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (*head == NULL)
        *head = t;
    else
    {
        struct node *p = *head;
        while (p->next)
            p = p->next;
        p->next = t;
    }
}

void sort(struct node *head)
{
    struct node *i, *j;
    int temp;
    for (i = head; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *cur = head, *next;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void concat()
{
    struct node *p = head1;
    while (p->next)
        p = p->next;
    p->next = head2;
}

void display(struct node *head)
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
    insert_end(&head1, 30);
    insert_end(&head1, 10);
    insert_end(&head1, 20);
    insert_end(&head2, 40);
    insert_end(&head2, 50);
    sort(head1);
    head1 = reverse(head1);
    concat();
    display(head1);
    return 0;
}

/* Output:
30 20 10 40 50
*/
