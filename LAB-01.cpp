#include<stdio.h>
#define max 5
int stack [max],top = -1;

void push(int val)
  {if (top==max-1){
    printf("Stack overflow");
   }
else{
    top++;
    stack[top]=val;
   }


}
void pop(){
    if(top==-1)
	{
        printf("Stack underflow");

    }
    else
	{
        printf(" This is the popped element %d\n",stack[top]);
        top--;
    }
}

void peek(){
if(top==-1)
    {
        printf("Stack under flow");
    }
    else
	{
        printf(" Top of stack is %d \n",stack[top]);
    }
}

void IsFull(){
if(top==max-1){
    printf(" !!!! stack overflow !!!\n");
}else{
	printf("stack is not full\n");
}
}
void IsEmpty(){
if(top==-1)
printf("stack underflow\n");

else{
	printf(" stack is not empty\n");
}
}

void display(){
     for(int i=top;i>=0;i--)
        {
          printf(" push: %d\n",stack[i]);
     }
}
int main(){
    push(55);
    push (20);
    push(30);
    display();
    pop();
    push(105);
    push(22);
    push(45);
    display();
    peek();
    IsEmpty();
    IsFull();
    return 0;
}