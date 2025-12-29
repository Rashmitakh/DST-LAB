/* WAP to convert a given valid parenthesized infix
arithmetic expression to postfix expression. The
expression consists of single character operands and the
binary operators + (plus), - (minus), * (multiply) and /
(divide) */

#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int priority(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i, k = 0;
    scanf("%s", infix);

    for (i = 0; infix[i]; i++)
    {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix[k++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("%s", postfix);
    return 0;
}

/* Output:
Input: (a+b)*c
Output: ab+c*
*/
