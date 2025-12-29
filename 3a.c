/* a) WAP to simulate the working of a queue of integers
using an array. Provide the following operations: Insert,
Delete, Display
The programshould print appropriate messagesfor queue
empty and queue overflow conditions */

#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void insert(int x)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}

void delete()
{
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        front++;
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        scanf("%d", &ch);
        if (ch == 1)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2)
            delete();
        else if (ch == 3)
            display();
        else
            break;
    }
    return 0;
}

/* Output:
1 10
1 20
1 30
3
10 20 30
2
3
20 30
*/
