// # QUEUE

#include<stdio.h>
void Enqueue();
void Dequeue();
int queue[4],rear=-1,front=-1,count=0;
main()
{ int ch=1,i; 
while(ch!=0)
{
printf("\tpress 1 for Enqueue\tpress 2 to Dequeue\tpress any key to Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: Enqueue();
break;
case 2: Dequeue();
break;
default: 
		for(i=front;i<=rear;i++)
        printf("%d\n", queue[i]);
        exit(0);
break;
}}}
void Enqueue()
{
 int x; 
if((rear==3 && front==0)||(rear==front-1))
 printf("Queue Overflowed\n");
 else 
 {
 if(front==-1)
 front=0;
 rear++;
 count++;
 scanf("%d",&x);
 queue[rear]=x;	
 }}
void Dequeue()
{
if(front==-1 || front>rear)
printf("Queue Underflowed\n");
else 
printf("element deleted is: %d", queue[front]);
front++;
count--;	
}
