//2108@system
//LIFO- STACK ; last in first out
#include<stdio.h>
 void push();
 void pop();
 int TOS=-1,n,a[100];
int main()
{
   int i,ch=1,x;
   printf("enter the number of elements to be inserted in stack:");
   scanf("%d",&n);
   while(ch!=0)
   {
	 printf("\tpress 1 for push\tpress 2 to print\tpress 3 for deletion\tpress 0 to exit\n");
	 scanf("%d",&ch);
	 switch(ch)
 	 {
		case 1: push();
		break;
		case 2: for(i=0;i<=TOS;i++)
        	printf("\n%d",a[i]);
			break;
		case 3: pop();
			break;
		default: printf("\nExit\n");
			break;
 	 }
    }
  return 0;
}

void push()
{
	int val;
	if(TOS>=n-1)
	{
	printf("\nStack overflowed");
	}
	else {
		TOS++;
		scanf("%d",&val);
		a[TOS]=val;
		printf("\nelement Inserted\n");
	}
}	
void pop()
{ 
	int b;	
	b=a[TOS];
	printf("\nDELETED ELEMENT=%d\n",b);
	TOS--;
}
