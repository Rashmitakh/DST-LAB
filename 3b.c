/* b ) WAP to simulate the working of a circular queue of
integers using an array. Provide the following operations:
Insert, Delete & Display
The programshould print appropriate messagesfor queue
empty and queue overflow conditions */

#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void insert(int x)
{
    if ((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("Queue Empty\n");
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        int i = front;
        while (1)
        {
            printf("%d ", q[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
    }
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
