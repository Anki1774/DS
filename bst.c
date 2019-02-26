#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node* left;
	int value;
	struct node* right;
};

struct node* head=NULL;

void insert(struct node* trav,int value)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->value=value;
	temp->left=temp->right=NULL;
	if(head==NULL)
      head=temp;
    else
	{
		if(value>trav->value)
		{
			if(trav->right==NULL)
			trav->right=temp;
			else
			{
				insert(trav->right,value);
			}
		}
		else
		{
			if(trav->left==NULL)
			trav->left=temp;
			else
			{
				insert(trav->left,value);
			}
		}
	  }  
      
}

void display(struct node* trav)
{
	if(trav==NULL)
	return;
	else
	{
		if(trav->left==NULL && trav->right==NULL)
		{
			printf("%d ",trav->value);
			return;
		}
		display(trav->left);
		printf("%d ",trav->value);
		display(trav->right);
		
	}
}

int main()
{
	struct node* trav=NULL;
	int choose,value;
	do{
		printf("\n 1- insert\n 2- display\n 0- exit");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				trav=head;
				printf("\n Enter the value:");
				scanf("%d",&value);
				insert(trav,value);
				break;
			case 2:
				trav=head;
			    display(trav);	
			    break;
			case 0:
			    break;
			default:
			    printf("\n Wrong choice. Please enter right choice");	    
		}
	}while(choose!=0);
}
