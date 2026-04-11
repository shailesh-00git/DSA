// implementation of circular queue
#include <stdio.h>
#define max 5
int queue[max];
int front = -1, rear = -1;
void enqueue(int value)
{
  if ((rear + 1) % max == front)
  {
    printf("Queue is full\n");
  }
  else if (front == -1 && rear == -1)
  {
    front = 0;
    rear = 0;
    queue[rear] = value;
  }
  else
  {
    rear = (rear + 1) % max;
    queue[rear] = value;
  }
}
void dequeue()
{
  if (front == -1 && rear == -1)
  {
    printf("Queue is empty\n");
  }
  else if (front == rear)
  {
    printf("%d is removed from queue\n", queue[front]);
    front = -1;
    rear = -1;
  }
  else
  {
    printf("%d is removed from queue\n", queue[front]);
    front = (front + 1) % max;
  }
}
void display()
{
  int i = front;

  while (i != rear)
  {
    printf("%d\t", queue[i]);
    i = (i + 1) % max;
  }
  printf("%d\t", queue[i]);
  printf("\n");
}
void IsFull()
{
  if ((rear + 1) % max == front)
  {
    printf("\nQueue is full\n");
  }
}
void IsEmpty()
{
  if (front == -1)
  {
    printf("\nQueue is empty\n");
  }
}
int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();
  dequeue();
  dequeue();
  enqueue(40);
  enqueue(50);
  enqueue(60);
  display();
  IsFull();
  dequeue();
  display();

  return 0;
}