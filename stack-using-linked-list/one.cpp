#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// PUSH operation
void push(int val)
{
    struct node *New = (struct node *)malloc(sizeof(struct node));

    New->data = val;
    New->next = top;   // works for both empty and non-empty stack
    top = New;
}

// DISPLAY stack
void display()
{
    struct node *temp = top;

    if (temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// POP operation (optional but important)
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    printf("Popped element = %d\n", temp->data);

    top = top->next;
    free(temp);
}

int main()
{
    push(20);
    push(30);
    push(40);

    printf("Stack elements:\n");
    display();

    pop();
    printf("After pop:\n");
    display();

    return 0;
}