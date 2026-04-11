// delete element in the middle and end
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  node *next;
};
node *head = NULL;

void InsBeg(int value)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = head;
  head = newNode;
  printf("\n----Inserted %d at Start----", value);
}
void InsAtEnd(int value)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = NULL;
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next =  newNode;
  printf("\n----Inserted %d at End----", value);
}
void InsAtSpecificPos(int value, int pos)
{
  if (pos <= 1 || head == NULL)
  {
    InsBeg(value);
    return;
  }
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  node *temp = head;
  // Move to the node just before desired position or the last node
  for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
  {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  printf("\n----Inserted %d at %d position----", value, pos);
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
void DelAtStart()
{
  node *temp = head;
  head = temp->next;
  printf("\n----Deleted %d from start----", temp->data);
  free(temp);
}
void DelFromEnd()
{
  if (head == NULL)
  {
    printf("\nLinked list is empty");
    return;
  }
  if (head->next == NULL)
  {
    printf("\n----Deleted %d from End----", head->data);
    free(head);
    head = NULL;
    return;
  }
  node *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  node *temp1 = temp->next;
  temp->next = NULL;
  printf("\n----Deleted %d from End----", temp1->data);
  free(temp1);
}
void DelFromSpecificPos(int pos)
{
  node *temp = head;
  for (int i = 1; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  node *temp1 = temp->next;
  temp->next = temp->next->next;
  printf("\n----Deleted %d from %d position----", temp1->data, pos);
  free(temp1);
}

int main()
{
  InsBeg(20);
  InsBeg(30);
  InsBeg(40);
  display();
  InsAtEnd(34);
  display();
  InsAtSpecificPos(56, 3);
  display();
  DelAtStart();
  display();
  DelFromEnd();
  display();
  DelFromSpecificPos(2);
  display();

  return 0;
}