#include<stdio.h>
main()
{
  int a[2]={5,6},b[2][2]={{1,2},{3,4}},i,j;
  printf("%d", a)    //The name of array reperesents it's starting address OR 0th Index.
  printf("%d", *a);   //Value stored at zero Index of array a[0].
  printf("\n%d", a+1);  //Address oF 1st Index.
  printf("\n%d", *(a+1)); //Value stored at first Index i.e second elemnt a[1].
  printf("\n%d", b);
  printf("\n%d", *b);
  printf("\n%d", b+1);
  printf("\n%d", *(b+1));
}	
