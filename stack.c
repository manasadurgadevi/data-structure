//stack eith linkedlist
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *link;
};
void push(int);
int pop();
int peak();
struct stack *top;
int main()
{
	int value;
	int choice;
	while(1)
          {
		  printf("1.push 2.pop 3.peak 4:exit\n");
		  printf("enter choice\n");
		  scanf("%d",&choice);
		  switch(choice)
		  {
			  case 1:printf("enter value\n");
				 scanf("%d",&value);
				 push(value);
				 break;

			  case 2:if(top==NULL)
				 printf("list is empty\n");
				 else 
				 printf("data poped is %d \n",pop());
			         break;
		          case 3: if(top==NULL)
			          printf("list is empty\n");
		                  else
			          printf("data is peak is %d",peak());
		          case 4: exit (0);
		  }
	  }
}	
void push(int d)
{
	struct stack *newnode=NULL;
	newnode= calloc(1,sizeof(struct stack));
        if (newnode==NULL)
	{
	 printf("stack is full\n");
	}
	else
	newnode->data=d;	
	newnode->link=top;
	top=newnode;
}
int pop()
{
	int d;
	struct stack *temp=NULL;
	if(top==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=top;
		top=top->link;
		d=temp->data;
		free(temp);
		temp=NULL;
	}
	return d;
}
int peak()
{
	return top->data;
}


		
