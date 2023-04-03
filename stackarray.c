//stack with array
#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top=-1;

void push(int);
int pop();
int peak();
int main()
{
        int value;
        int choice;
        while(1)
        {
                printf("1.push 2. pop 3. peak 4.exit \n");
                printf("enter choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:printf("enter the data\n");
                               scanf("%d",&value);
                               push(value);
                               break;
                        case 2:if(top==-1)
                               printf("list is empty\n");
                               else
                                      printf("print the pop data %d \n",pop());
			       break;
                        case 3:if(top==-1)
                               printf("list is empty\n");
                               else
                                    printf("print the peak data %d\n",peak());
			       break;
                        case 4: exit(0);
                }
        }
}
void push(int d)
{
	if(top==max-1)
	{
		printf("stack is full\n");
	}
	else
	{
		stack [++top]=d;
	}
}
int pop()
{
	return stack[top--];
}
int peak()
{
	return stack[top];
}
