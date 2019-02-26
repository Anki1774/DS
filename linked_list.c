	#include<stdio.h>
//#include<iostream>
//using namespace std;

struct node{
	int data;
	struct node *next;
};

//struct node *root=NULL;

void append(struct node** ,int);
void reverse(struct node** );
void display(struct node** );
void del(struct node** ,int);
int list_len(struct node**);
void del_all(struct node**);




main()
{
	int data;
	int choose;
	int ch;
	int press,pos;
	struct node* head=NULL;
	do{
		
		printf("\n Press 1 to Append \n 2 - display \n 3- reverse\n 4-delete\n 0-exit");
		scanf("%d",&choose);
		
		switch(choose)
		{
			case 1:
				{
					do{
					printf("\n Enter value in the node:");
					scanf("%d",&data);
					append(&head,data);
					printf("\n wanna enter more :");
					scanf("%d",&ch);
				   }while(ch!=0);
				}break;
			
			case 2:
			    {
			    	display(&head);
			    	printf("\n\n%d",&head);
			    	printf("\n%d",&(head->next));
			 	
				 }break;
			
			case 3:
			    {
			    	reverse(&head);
			    	printf("\n Linked list has been succesfully reversed");
						 }break;
						 
			case 4:
			   {
			   	printf("1-delete a particular node \n 2- to delete whole linked list ");
			   	scanf("%d",&press);
			   	if(press==1)
			   	{
			   		printf("\n Which node you want to delete - Enter its serial number:");
			   		scanf("%d",&pos);
			   		del(&head,pos);
				   }
				   else if(press==2)
				   {
				   		del_all(&head);
				   		printf("\n List is deleted successfully ");
				   }
				   else
				   {
				   	printf("\n Wrong choice!!!!!!!!!!");
				   }
							}break;
			case 0:
			    exit(0);		
					 	 	
				 
				
		}
		
	
	}while(choose!=0);
	
}




void display(struct node** root)
{
		
	struct node *q;
	q=*root;
	
	if(*root==NULL)
	printf("\n List is empty");
	else
	{
		while(q->next!=NULL)
		{
			printf(" %d ->",q->data);
			q=q->next;
    	}
    	printf("%d",q->data);
	}
	

}

void append(struct node **root,int data)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(*root==NULL)
	{
		*root=temp;
	}
	else
	{
		struct node *p;
		p=*root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
void reverse(struct node** root)
{
	
	struct node* prev=NULL;
	struct node* current=*root;
	struct node* next_node=NULL;
	
		while(current!=NULL)
	{
		next_node=current->next;
		current->next=prev;
		prev=current;
		current=next_node;
		
	}
	*root=prev;

	
}

void del(struct node** root,int i)
{
	struct node * p,*q;
	p=*root;
	int count=1;
	
	if(i>list_len(&(*root)))
	{
		printf("\n sorry index does not exist !!!!!!!!!");
	}
	else
	{
		if(i==1)
		{
			*root=(*root)->next;
			free(p);
		}
		else
		{
			while(count!=i&&p->next!=NULL)
	    	{
				q=p;
				p=p->next;
				count++;
			}
			q->next=p->next;
			free(p);
		}
	
	}

}
int list_len(struct node** root)
{
	int count=1;
	struct node* p=*root;
	while(p->next!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}
void del_all(struct node** root)
{
	struct node*p;
	while((*root)!=NULL)
	{
		p=*root;
		(*root)=(*root)->next;
		free(p);
	}
}

