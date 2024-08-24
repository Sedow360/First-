#include <stdio.h>

#define N 5
int stack[N];
int top =-1;

void push();
void pop();
void peek();
void disp();

int main()
{
    int ch;

    printf("1: Push\n2: Pop\n3: Peek\n4: Display\n5: End operation\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 5) {break;}
        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: disp(); break;
        }
    }

    printf("Thanks!\n");
    return 0;
}

void push()
{
    if (top > 3)
    {
        printf("Overflow!\n");
        return;
    }
    else 
    {
        int n; printf("Enter the element: "); 
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("%d is popped off the stack!\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Empty stack!\n");
        return;
    }

    printf("%d is at the top!\n", stack[top]);
}

void disp()
{
    if (top == -1)
    {
        printf("Empty stack!\n");
        return;
    }
    printf("The stack is as follows: ");
    for (int t = 0; t<=top; t++)
    {
        printf("%d ", stack[t]);
    }
    printf("\n");
}