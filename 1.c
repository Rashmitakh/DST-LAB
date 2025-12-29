/* Write a program to simulate the working of stack using an 
array with the following:
a) Push
b) Pop
c) Display
The program should print appropriate messages for stack
overflow, stack underflow */

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

/* PUSH OPERATION */
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", x);
    }
    else
    {
        top++;
        stack[top] = x;
        printf("Element %d pushed successfully\n", x);
    }
}

/* POP OPERATION */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty\n");
    }
    else
    {
        printf("Element %d popped successfully\n", stack[top]);
        top--;
    }
}

/* DISPLAY OPERATION */
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom): ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again\n");
        }
    }
}


/*
    --- STACK MENU ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 10
Element 10 pushed successfully

Enter your choice: 1
Enter value to push: 20
Element 20 pushed successfully

Enter your choice: 3
Stack elements (Top to Bottom): 20 10

Enter your choice: 2
Element 20 popped successfully

Enter your choice: 3
Stack elements (Top to Bottom): 10
*/

