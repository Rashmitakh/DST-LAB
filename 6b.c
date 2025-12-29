/* b) WAP to Implement Single Link List to simulate Stack &
Queue Operations. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void push(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = top;
    top = t;
}

void pop()
{
    if (top)
    {
        struct node *t = top;
        top = top->next;
        free(t);
    }
}

void enqueue(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (rear == NULL)
        front = rear = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

void dequeue()
{
    if (front)
    {
        struct node *t = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        free(t);
    }
}

void display_stack()
{
    struct node *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void display_queue()
{
    struct node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    pop();
    display_stack();
    enqueue(1);
    enqueue(2);
    dequeue();
    display_queue();
    return 0;
}

/* Output:
10
2
*/
