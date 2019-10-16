#include<stdio.h>
int ar1[3][3],ar2[3][3],short1[3][10],short2[3][10],short3[3][10];
void make_sparse(int);
void reduce_sparse(int);
void print_short(int);
int non_zero(int);
void add();
int main()
{
	printf("Enter sparse matrix 1\n");
	make_sparse(1);
	printf("Enter sparse matrix 2\n");
	make_sparse(2);
	reduce_sparse(1);
	reduce_sparse(2);
	printf("\nreduced form of sparse matrix 1 : \n\n");
	print_short(1);
	printf("reduced form of matrix 2 : \n");
	print_short(2);
	printf("\nSum of matrix a and b : \n");
	add();	
}
void make_sparse(int n)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(n==1)
			scanf("%d",&ar1[i][j]);
			else if(n==2)
			scanf("%d",&ar2[i][j]);
		}
	}
}
int non_zero(int n)
{
	int i,j,NZ=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(n==1)
			{
				if(ar1[i][j]!=0)
				NZ++;
			}
			else if(n==2)
			{
				if(ar2[i][j]!=0)
				NZ++;
			}
			
		}
	}
	return NZ;
}
void reduce_sparse(int n)
{
	int i,j,x=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(n==1)
			{
				if(ar1[i][j]!=0)
				{
					short1[0][x]=i;
					short1[1][x]=j;
					short1[2][x]=ar1[i][j];
					x++;
				}
			}
			if(n==2)
			{
				if(ar2[i][j]!=0)
				{
					short2[0][x]=i;
					short2[1][x]=j;
					short2[2][x]=ar2[i][j];
					x++;
				}
			}
		}
	}
}
void print_short(int n)
{
	int i,j;
	if(n==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<non_zero(1);j++)
			{
				printf("%d\t",short1[i][j]);
			}
			printf("\n");
		}
	}
	if(n==2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<non_zero(2);j++)
			{
				printf("%d\t",short2[i][j]);
			}
			printf("\n");
		}
	}
}
void add()
{
	int p1=0,p2=0,p3=0,temp=0,i,j;
	while(p1<non_zero(1)&&p2<non_zero(2))
	{
		if(short1[0][p1]<short2[0][p2])
		{
			short3[0][p3]=short1[0][p1];
			short3[1][p3]=short1[1][p1];
			short3[2][p3]=short1[2][p1];
			p1++;
			p3++;
		}
		else if(short1[0][p1]>short2[0][p2])
		{
			short3[0][p3]=short2[0][p2];
			short3[1][p3]=short2[1][p2];
			short3[2][p3]=short2[2][p2];
			p2++;
			p3++;
		}
		else
		{
			if(short1[1][p1]<short2[1][p2])
			{
				short3[0][p3]=short1[0][p1];
				short3[1][p3]=short1[1][p1];
				short3[2][p3]=short1[2][p1];
				p1++;
				p3++;
			}
			else if(short1[1][p1]>short2[1][p2])
			{
				short3[0][p3]=short2[0][p2];
				short3[1][p3]=short2[1][p2];
				short3[2][p3]=short2[2][p2];
				p2++;
				p3++;
			}
			else {
				short3[0][p3]=short1[0][p1];
				short3[1][p3]=short1[1][p1];
				short3[2][p3]=short1[2][p1]+short2[2][p2];
				p1++;
				p2++;
				p3++;
			}
		}
	}
	if(p1<non_zero(1))
	{
		while(p1!=non_zero(1))
		{
			short3[0][p3]=short1[0][p1];
			short3[1][p3]=short1[1][p1];
			short3[2][p3]=short1[2][p1];
			p1++;
			p3++;
		}
	}
	if(p2<non_zero(2))
	{
		while(p2!=non_zero(2))
		{
			short3[0][p3]=short2[0][p2];
			short3[1][p3]=short2[1][p2];
			short3[2][p3]=short2[2][p2];
			p2++;
			p3++;
		}	
	}
	for(i=0;i<3;i++)
	{
		for(temp=0;temp<p3;temp++)
		{
			printf("%d\t",short3[i][temp]);
		}
		printf("\n");
	}
	printf("\n\nNow transpose of this matrix is \n\n");
	for(i=0;i<p3;i++)
	{
		temp=short3[0][i];
		short3[0][i]=short3[1][i];
		short3[1][i]=temp;
	}
	for(i=0;i<p3-1;i++)
	{
		for(j=0;j<p3-i-i;j++)
		{
			if(short3[0][j]>short3[0][j+1])
			{
				short3[0][j]=short3[0][j+1]+short3[0][j]-(short3[0][j+1]=short3[0][j]);
				short3[1][j]=short3[1][j+1]+short3[1][j]-(short3[1][j+1]=short3[1][j]);
				short3[2][j]=short3[2][j+1]+short3[2][j]-(short3[2][j+1]=short3[2][j]);
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<p3;j++)
		{
			printf("%d\t",short3[i][j]);
		}
		printf("\n");
	}
}
