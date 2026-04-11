#include <stdio.h>
#define max 5
int queue[max];
int front = -1, rear = -1;

void enqueue(int value)
{
  if (rear == max - 1)
  {
    printf("Queue is full");
  }
  else
  {
    if (front == -1 && rear == -1)
    {
      front = 0;
      rear = 0;
    }
    else
    {
      rear += 1;
    }
    queue[rear] = value;
  }
}
void dequeue()
{
  if ((front == -1 && rear == -1) || (front > rear))
    printf("Queue is empty\n");

  else
  {
    printf("\nremoved: %d\n", queue[front]);
    front = front + 1;
  }
  if (rear == front)
  {
    front = -1;
    rear = -1;
  }
}

void display()
{
  int i;
  for (i = front; i <= rear; i++)
  {
    printf("%d\t", queue[i]);
  }
}

void isempty()
{
  if (front == -1 || front > rear)
  {
    printf("\nqueue is empty\n");
  }
}
void isfull()
{
  if (rear == max - 1)
  {
    printf("\nqueue is full\n");
  }
}
int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  display();
  dequeue();
  display();
  dequeue();
  display();
  enqueue(100);

  printf("\n");
  display();

  isfull();
  return 0;
}
