// to insert the element in the linkedd list fron the begning
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
int main()
{
  InsBeg(20);
  InsBeg(30);
  InsBeg(40);
  display();
  return 0;
}