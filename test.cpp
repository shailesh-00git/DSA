#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
  if (top < MAX - 1)
  {
    stack[++top] = val;
  }
}

int pop()
{
  if (top >= 0)
  {
    return stack[top--];
  }
  return 0;
}

int main()
{
  int num = 0;
  char ch;
  int result = 0;

  printf("Enter postfix expression (space-separated, e.g., 2 2 6 4 + * ^): ");

  while (scanf("%c", &ch) == 1)
  {
    if (ch == '\n')
    {
      break;
    }

    if (isdigit(ch))
    {
      num = num * 10 + (ch - '0');
    }
    else if (ch == ' ')
    {
      if (num > 0 || (top >= 0 && stack[top] == 0))
      {
        push(num);
        num = 0;
      }
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
      int operand1 = pop();
      int operand2 = pop();
      int result = 0;

      if (ch == '+')
      {
        result = operand1 + operand2;
      }
      else if (ch == '-')
      {
        result = operand1 - operand2;
      }
      else if (ch == '*')
      {
        result = operand1 * operand2;
      }
      else if (ch == '/')
      {
        result = operand1 / operand2;
      }
      else if (ch == '^')
      {
        result = (int)pow(operand1, operand2);
      }

      push(result);
      printf("Operation %c: %d %c %d = %d\n", ch, operand1, ch, operand2, result);
    }
  }

  result = pop();
  printf("\nFinal Result: %d\n", result);

  return 0;
}