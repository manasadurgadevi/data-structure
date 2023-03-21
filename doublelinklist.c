#include<stdio.h>
#include<stdlib.h>
struct student {
	int roll;
	char name [20];
	float marks;
	struct student*prev,*link;
};

struct student * add_last(struct student *);
struct student * add_first(struct student*);
struct student* del_first(struct student*);
struct student * del_last(struct student*);
struct student* reverse(struct student*);
void display (struct student*);

int main()
{
	struct student *head=NULL;
	int choice;
	while(1)
	{
		printf("1: add_last 2: add_first 3: display 4: del_first 5:del_last 6: reverse\n");
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=add_last(head);
				break;
			case 2: head=add_first(head);
				break;
			case 3: display(head);
			        break;	
			case 4: head=del_first(head);
			        break;
			case 5: head=del_last(head);
			        break;	
			case 6: head=reverse(head);
			        break;	
		}
	}
}

struct student* add_last (struct student*ptr)
{
	struct student * temp =NULL,*newnode=NULL,*prev=NULL;
	newnode=(struct student*)calloc(1,sizeof(struct student)) ;
	if(newnode==NULL)
	{
		printf("list is empty\n");
	}
        else
	{	
	printf("enter roll number\n");
	scanf("%d",&newnode->roll);
	printf("enter name\n");
	scanf("%s",newnode->name);
	printf("enter marks\n");
	scanf("%f",&newnode->marks);
	if(ptr==NULL)
	{
		ptr=newnode;
	}
	else
	{
		temp =ptr;
		//prev=temp;
	while(temp->link!=NULL)
	{
		temp =temp->link;
	}
	temp->link=newnode;
	newnode->prev=temp;
	}
	}
	return ptr;
}

struct student * add_first(struct student *ptr)
{
	struct student *newnode=NULL;
	newnode=(struct student*)calloc(1,sizeof(struct student));
	if(newnode==NULL)
	{
		printf("list is empty\n");
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
		if(ptr)
	        ptr->prev=newnode;
		ptr=newnode;
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

struct student* del_first(struct student*ptr)
{
	struct student *temp=NULL;
	if(ptr==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=ptr;
		ptr=ptr->link;
		if(ptr)
                ptr->prev=NULL; 
		free(temp);
		temp=NULL;
	}
	return ptr;
}
struct student* del_last(struct student*ptr)
{
	struct student * temp=NULL;
	if(ptr==NULL)
	{
		printf("list is empty\n");
	}
	else if(ptr->link==NULL)
	{
		free (ptr);
		ptr=NULL;
	}
	else
	{
		temp=ptr;
		while(temp->link!=NULL)
		{
			//prev=temp;
			temp=temp->link;
		}
		temp->prev->link=NULL;
		free(temp);
		temp=NULL;
	}
	return ptr;
}
			
struct student* reverse(struct student* ptr)
{
	struct student *temp=NULL,*p=NULL;
        //newnode=(struct student*) calloc(1,sizeof(struct student));
        if(ptr==NULL)
        {
                printf("list is empty\n");
        }
        
	else if(ptr->link==NULL )
		{
			printf("list as one node\n");
		}
		else
		{
			p=ptr;
			while(p)
			{
			temp=p->prev;
			p->prev=p->link;
			p->link=temp;
			p=p->prev;
			}
			ptr=temp->prev;

		}
	
	return ptr;
}

