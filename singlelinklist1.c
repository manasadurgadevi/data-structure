#include<stdio.h>
#include<stdlib.h>

struct student {
	int roll;
	char name[20];
	float marks;
	struct student *link;
};
struct student * add_last(struct student *);
void display (struct student *);
struct student * add_first(struct student *);
struct student * del_first(struct student *);
struct student * del_last(struct student *);
int main()
{
	struct student *head=NULL;
	int choice;
        while(1)
	{
	  printf("1:add_last 2:display  3:add_first 4:del_first 5:del_last 6:exit \n");
	  printf("enter choice\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	    case 1 :head=add_last(head);
                 break;
            case 2 : display(head);
	         break;	
            
            case 3 :head=add_first(head);
		    break;
            case 4 :head=del_first(head);
		    break;
            case 5 :head=del_last(head);
		    break;
            case 6 :exit(0);		    

	  }
	}
}	
struct student * add_last(struct student*ptr)
{
	struct student *newnode=NULL,*temp =NULL;
	//creating the node
	//newnode = malloc(sizeof(struct student));
        newnode=(struct student *)calloc(1,sizeof(struct student));
	if(newnode ==NULL)
	{
		printf("node is not creacted\n");
	}
	else
	{
		printf("enter roll number\n");
		scanf("%d",&newnode->roll);
		printf("enter name\n");
		scanf("%s",newnode->name);
		printf("enter marks\n");
		scanf("%f",&newnode->marks);
        //add_last
	    if(ptr==NULL)
	    {  
		ptr=newnode;
	    }
	    else
	    {
		temp =ptr;
	    while(temp->link!=NULL)
	    {
		temp =temp->link;
	    }
	    temp->link=newnode;
	    }
	}
	return ptr;
}
void display(struct student*ptr)
{
	if(ptr==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
			ptr=ptr->link;
		}
	}
}
struct student* add_first(struct student*ptr)
{
	struct student* newnode=NULL;
	newnode=(struct student *)calloc(1,sizeof(struct student));
        if(newnode ==NULL)
        {
                printf("node is not creacted\n");
        }
        else
        {
                printf("enter roll number\n");
                scanf("%d",&newnode->roll);
                printf("enter name\n");
                scanf("%s",newnode->name);
                printf("enter marks\n");
                scanf("%f",&newnode->marks);

	newnode->link=ptr;
	ptr=newnode;


	}
	return ptr;
}

struct student* del_first(struct student*ptr)
{
	struct student*temp =NULL;
	if(ptr==NULL)
	{
		printf("enter list is empty\n");
	}
	else
	{
		temp=ptr;
	        ptr=ptr->link;
		free(temp);
		temp=NULL;
	}
	return ptr;
}
struct student* del_last(struct student *ptr)
{
	struct student * temp=NULL,*prev=NULL;

	if(ptr==NULL)
	{
		printf("list is empty\n");
	}
	else if(ptr->link==NULL)
	{
		free(ptr);
		ptr=NULL;
	}
	else
	{
		temp=ptr;
		while(temp->link!=NULL)
		{
			prev=temp;
			temp =temp->link;
		}
		prev->link=NULL;
		free(temp);
		temp=NULL;
	}
	return ptr;
}


