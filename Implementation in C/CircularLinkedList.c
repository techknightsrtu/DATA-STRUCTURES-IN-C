#include<stdio.h>
#include<malloc.h>
struct node
{
	int Data;
	struct node *left;
	struct node *right;
}*Head=NULL,*p,*n,*T,*temp;
	int position,i;
void create()
{
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Data\n");
    scanf("%d", &p->Data);
	if(Head==NULL)
	{
		Head=temp=p;
		p->left=NULL;
		p->right=NULL;
	}
	else if(temp->right==NULL)
	{
	p->left=temp;
	p->right=NULL;
	temp->right=p;
	temp=temp->right;	
	}
}
/*.................................................................*/
void ADD()
{
	printf("Enter the position at which data is to be inserted: ");
	scanf("%d",&position);
	p=(struct node*)malloc(sizeof(struct node));
	T=Head;
	printf("Enter the Data\n");
    scanf("%d", &p->Data);
    switch(position)
    {
    	case 1: p->left=NULL;
    	p->right= Head;
    	Head=p;
    	break;
    	case 2: p->left=T;
    	p->right=T->right;
    	T->right=T->right->left=p;
    	break;
    	default:for(i=0;i<position-2;i++)
    		{
    			T=T->right;
			}
			p->left=T;
			p->right=T->right;
			T->right=T->right->left=p;	
	}
}
/*...................................................................................*/
void print()
{
	struct node *r;
 	n=Head;
	 while(n!=NULL)
 	{
 	printf("%d	",n->Data);
 	if(n->right==NULL)
	r=n;
 	n=n->right;
	}
	printf("\n\n%d	",r->Data);	
	
	while(r->left!=NULL)
	{
		r=r->left;
		printf("%d	",r->Data);
	}
}
/*.................................................................................................*/
void Delete()
{
	printf("Enter the position to be deleted: ");
	scanf("%d",&position);
	n=Head;
	switch(position)
	{
		case 1: Head=n->right;
		n->right->left=NULL;
		free(n);
		break;
		case 2: T=n->right;
		n->right=T->right;
		free(T);
		break;
		default: for(i=0;i<position-1;i++)
		{
			n=n->right;
		}
		n->left->right=n->right;
		n->right->left=n->left;
		free(n);
	}
}
main()
{
	int ch;
	while(1)
	{
		printf("enter 1 to create/ 2 to add at position(start or in between)/ 3 to print\n4 to delete:\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: create();
		break;
		case 2: ADD();
		break;
		case 3: print();
		break;
		case 4: Delete();
		break;
		default: return(0);
		}
	}
}
