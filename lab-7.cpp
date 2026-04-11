// doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
  node *prev;
  int data;
  node *next;
};

node *head = NULL;

void InsAtBeg(int val)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = val;
  newNode->prev = NULL;
  newNode->next = head;
  if (head != NULL) // ✅ Fix 3: update old head's prev pointer
    head->prev = newNode;
  head = newNode;
  // printf("\n\n----Added %d At start----", val);
}

void InsAtEnd(int value)
{
  node *newNode = (node *)malloc(sizeof(node));
  node *temp = head;

  newNode->data = value;
  newNode->next = NULL;

  while (temp->next != NULL)
    temp = temp->next;

  newNode->prev = temp; // ✅ Fix 2: set prev to the current last node
  temp->next = newNode;
  printf("\n\n----Added %d At End----", value);
}

void display()
{
  printf("\n");
  int index = 1;
  node *temp = head;
  while (temp != NULL)
  {
    printf("Value %d: %d\t", index, temp->data);
    temp = temp->next;
    index++;
  }
}

void DelFromBeg()
{
  node *temp = head;
  head = temp->next;
  if (head != NULL)
    head->prev = NULL;
  printf("\n\n----Deleted %d from start----", temp->data);
  free(temp);
}

void DelFromEnd()
{
  node *temp = head;
  while (temp->next->next != NULL)
    temp = temp->next;

  node *temp1 = temp->next;
  temp->next = NULL;

  printf("\n\n----Deleted %d from End----", temp1->data);
  free(temp1);
  // ✅ Fix 1: removed incorrect free(temp) — temp is still in the list!
}

int main()
{
  printf("Initially List is Empty");
  InsAtBeg(10);
  InsAtBeg(20);
  InsAtBeg(30);
  display();
  DelFromBeg();
  display();
  InsAtEnd(60);
  display();
  DelFromEnd();
  display();
  return 0;
}