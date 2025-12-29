/* Write a program to simulate the working of stack using an 
array with the following:
a) Push
b) Pop
c) Display
The program should print appropriate messages for stack
overflow, stack underflow */

#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void display()
{
    if (top == -1)
        printf("Stack Empty\n");
    else
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
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
            push(x);
        }
        else if (ch == 2)
            pop();
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
3
20 10
2
3
10
*/
