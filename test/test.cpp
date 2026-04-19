
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    node *next;
};
node *head = NULL;
void insBeg(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insEnd(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        node *temp = head;
        newnode->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void atMid(int pos, int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display()
{
    printf("\n");
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("null");
}
void delBeg()
{
    node *temp = head;
    // if one node
    if (head->next == NULL)
    {
        temp = head;
        printf("\n removed %d \n", temp->data);
        free(temp);
    }
    else
    {
        temp = head;
        head = temp->next;
        printf("\n removed %d \n", temp->data);
        free(temp);
    }
}
void delEnd()
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = NULL;
    printf("\n removed %d \n", temp1->data);
    free(temp1);
}
void delMid(int pos)
{
    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp->next->next;
    printf("\n removed %d \n", temp1->data);
    free(temp1);
}
int main()
{

    insBeg(1);
    insBeg(2);
    display();
    insEnd(3);
    insEnd(4);
    display();
    atMid(3, 33);
    display();
    delBeg();
    display();
    delEnd();
    display();
    insEnd(893);
    display();
    delMid(3);
    display();
    return 0;
}