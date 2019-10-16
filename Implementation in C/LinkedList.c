#include<stdio.h>
#include<stdlib.h>
int i,x,pos;
struct node
{
	int data;
	struct node *link;
}*s=NULL;
struct node *ptr, *temp,*n;
//..................................................................
void INSERT()
{	
	struct node *a;
	ptr= (struct node *)malloc(sizeof(struct node)); 
	printf("Enter the position where u need to add the data: ");
	scanf("%d",&x);
	printf("\nEnter the data of new node:	");
	scanf("%d",&ptr->data);
	temp=s;
	switch(x)
	{
	case 1: ptr->link=s;
	        s=ptr;	
     	break;
	case 2: ptr->link=temp->link;
	        temp->link=ptr;
	    break;
	default:
	        for(i=0;i<x-2;i++)
	{
		    a=temp->link;
    	    temp=a;
	}
	        ptr->link=temp->link;
        	a->link=ptr;		
        break;
}
}
//..................................................................
 void creation()
{  
	ptr= (struct node *)malloc(sizeof(struct node)); 
    printf("Enter the Data\n");
    scanf("%d", &ptr->data);
	
 	if(s==NULL)
    {
		s=temp=ptr;
    }
	else if(temp->link==NULL)
    { 
    	temp->link=ptr;
    	temp=ptr;
	}
	ptr->link=NULL;
}
//..................................................................
 void display()
{
	n=s;
	while(n!=NULL)
	{
		printf("%d\t",n->data);
		n=n->link;
	}
}
//..................................................................

  void del()
{   struct node *t;    
		if(s==NULL)
		printf("UNDERFLOWED");
		else
		{
        printf("Enter the position to be deleted");
		scanf("%d",&pos);
		n=s;
		switch(pos)
		{
		case 1: s=n->link;
		        free(n);
			 break;
		case 2: t=n->link;	
	        	n->link=n->link->link;
	         	free(t);
			 break;
		default:
		        for(i=1;i<pos-1;i++)
		{ 
		        n=n->link;
		}
		        t=n->link;	
	           	n->link=n->link->link;
	        	free(t);
		break;
 		}
}
}
main()
 {
  	int ch;
    while(1)
	{
		printf("\nENTER 1 TO ADD THE NODE & 2 TO PRINT & 3 to add data at some position & 4 to delete \n Press 0 TO EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:    creation();
			break;
		case 2:    display();
			break;
		case 3:    INSERT();
			break;
		case 4:    del();
		    break;		
		case 0:	   exit(0);	
			break;
		default: printf("Invalid choice");
			exit(0);
			break;
		}	
	} 	
}
