#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
struct BST * create()
{
	struct BST *N;
	printf("Enter the Data: ");
	N=(struct BST *)malloc(sizeof(struct BST));
	scanf("%d",&N->data);
	N->left=N->right=NULL;
	return N;
}
void insert(struct BST *root,struct BST * N)
{
	if(N->data<root->data)
	{
		if(root->left!=NULL)
		insert(root->left,N);
	else
	root->left=N;
	}
	if(N->data>root->data)
	{
		if(root->right!=NULL)
		insert(root->right,N);
		else
		root->right=N;
	}
	if(N->data==root->data)
	{
		if(root->right!=NULL)
		insert(root->right,N);
		else
		root->right=N;
	}
}
void inorder(struct BST *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
main()
{
	char ch;
	struct BST *N,*root=NULL;
	do
	{
		N=create();
		if(root==NULL)
			root=N;
		else if(root!=NULL)
			insert(root,N);
			printf("do you want to add more(Y to yes and N to no): ");
			getchar();
			scanf("%c",&ch);
	}while(ch=='y'|| ch=='Y');
	printf("Inorder traverse\n");
	inorder(root);
}
